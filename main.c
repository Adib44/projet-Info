#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 512

void traiter_ligne(char* line, FILE** current_output);
void ouvrir_nouvelle_section(char* line, FILE** current_output);
void fermer_section(FILE** current_output);
void ecrire_contenu(char* line, FILE* current_output);

int main() {
    const char* filename = "book.txt";
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open file <%s>\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[LINE_SIZE];
    FILE* current_output = NULL;

    while (fgets(line, sizeof(line), file)) {
        traiter_ligne(line, &current_output);
    }

    // Fermer le dernier fichier si nécessaire
    if (current_output != NULL) {
        fclose(current_output);
    }

    fclose(file);
    return 0;
}


void traiter_ligne(char* line, FILE** current_output) {
    if (strstr(line, "<section name=")) {
        ouvrir_nouvelle_section(line, current_output);
    } else if (strstr(line, "</section>")) {
        fermer_section(current_output);
    } else if (*current_output != NULL) {
        ecrire_contenu(line, *current_output);
    }
}


void ouvrir_nouvelle_section(char* line, FILE** current_output) {
    char section_name[100];
    
    // Extraire le nom de section
    sscanf(line, "<section name=\"%[^\"]\">", section_name);

    // Créer un nom de fichier
    char filename[128];
    snprintf(filename, sizeof(filename), "%s.html", section_name);

    // Fermer l'ancien fichier si nécessaire
    if (*current_output != NULL) {
        fclose(*current_output);
    }

    // Ouvrir le nouveau fichier
    *current_output = fopen(filename, "w");
    if (*current_output == NULL) {
        printf("Erreur ouverture fichier <%s>\n", filename);
        exit(EXIT_FAILURE);
    }

    // Écrire le début du HTML
    fprintf(*current_output, "<html><head><title>%s</title></head><body>\n", section_name);
    fprintf(*current_output, "<h1>%s</h1>\n", section_name);
}


void fermer_section(FILE** current_output) {
    if (*current_output != NULL) {
        fprintf(*current_output, "</body></html>\n");
        fclose(*current_output);
        *current_output = NULL;
    }
}


void ecrire_contenu(char* line, FILE* current_output) {
    fprintf(current_output, "<p>%s</p>\n", line);
}



