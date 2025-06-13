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
