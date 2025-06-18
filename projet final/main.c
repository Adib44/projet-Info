#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 513 // 512 + 1 pour '\0'
FILE* read();

FILE* creation_pagehtml(char* page_name);
void paragraph(FILE* page, char* line );
char choix(FILE* page, char* line );
void fieldset(FILE* page,char* line);

int main(void){
    int jeu = 11;
    char title[LINE_SIZE];
    int id;
    FILE* page=NULL; /* pointeur ne valant rien */
    FILE* lecture = read();
    char page_name[LINE_SIZE];


    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), lecture )) {
        if(strstr(line, "<chapter")==line) {

            if(page != NULL) {
                fclose(page);
            }

            sscanf(line, "<chapter id=\"%d\">%[^<]</chapter>", &id, title);
            snprintf(page_name, sizeof(page_name), "%02d.html", id);
            printf("%s\n", page_name);
            page=creation_pagehtml(page_name);
            fprintf(page, "<!DOCTYPE html>\n"

        "<html lang=\"fr\">\n"
        "<head>\n"
        "<meta charset=\"utf-8\">\n"
        "<title>%s</title>\n"
        "<link rel=\"preconnect\" href=\"projet_final.css\"rel=stylesheet>\n"
        " <script src=""loader.js defer></script>"
        "<style>\n"
  "body {\n"
    "background-color: #191970; /* Bleu minuit */\n"
    "color: white;              /* Pour un bon contraste du texte */\n"
    "font-family: ""'Times New Roman', Times"", serif; /* Option médiévale chic */\n"
  "}\n"
  "fieldset{\n"
    "width: 100;\n"
    "height: 50;\n"
    "border:none;\n"

"}\n"
".box{\n"
  "display: flex;\n"
  "justify-content: center;\n"
  "background-color: #d4af37;\n"
  " border: 2px solid; \n"        /* bordure or antique */
  "border-radius: 12px;\n "             /* arrondi des coins */
  "padding: 16px;\n"
"}\n"
".loader-container {\n"
  "position: fixed;\n"
  "top: 0;\n"
  "left: 0;\n"
  "z-index: 999;\n"
  "width: 100%;\n"
  "height: 100%;\n"
  "background-color: #fff;\n"
  "transition: opacity 1s ease-in-out, visibility 1s ease-in-out;\n"
"}\n"
".loader-container.Hidden {\n"
  "opacity: 0;\n"
  "visibility: hidden;\n"
"}\n"

".Loader {\n"
  "width: 120px;\n"
  "height: 120px;\n"
  "border: 16px solid #e5e5e5;\n"
  "border-top: 16px solid #007bff;\n"
  "border-radius: 50%;\n"
  "box-shadow: 0 0 6px 2px rgba(0, 0, 0, 0.2);\n"
  "position: absolute;\n"
  "top: 50%;\n"
  "left: 50%;\n"
  "transform: translate(-50%, -50%) rotate(0deg);\n"
  "animation: Loader 1s linear infinite;\n"
"}\n"
"@keyframes Loader {\n"
  "100% {\n"
    "transform: translate(-50%, -50%) rotate(360deg);\n"
  "}\n"
"}\n"

"</style>\n"

        "</head>\n"
        "<body>\n"
        "<div class=""loader-container"">\n"
      "<div class=""Loader""></div>\n"
    "</div>\n"
        "<h1>%s</h1>\n",title,title);
            
        }
        else if(page != NULL) {
            if(strstr(line, "<p>")==line) {
                paragraph(page, line);
            }
            else if(strstr(line, "<choice")==line) {
                choix(page, line);

            }
            else if(strstr(line, "<fieldset")==line) {
                fieldset(page,line);
            }
            else if(strstr(line, "<chapter id =""10""")||strstr(line, "<chapter id =""09""")==line){
                fprintf(page,"<a href=\"jeu.html\" class=\"box\">\n <p><br><strong> Effectuer ce choix</strong></p>\n </a>" );

            }

        }

    }
}
FILE* read() {
    FILE* lecture = fopen("book.txt", "r");
    if (!lecture) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
        return lecture;
    }
}
FILE* creation_pagehtml(char* page_name) {

    FILE* fichier = fopen( page_name, "w");  // ouverture en écriture

    if (!fichier) {
       fprintf(stderr, "Erreur  lors de la creation du fichier veuiller reessayer\n");
        exit(EXIT_FAILURE);
    }
    return fichier;
}

void paragraph(FILE* page, char* line ){
    char texte[LINE_SIZE];
    sscanf(line, "<p>%[^<]</p>", texte);
    fprintf(page, "  <p>%s</p>\n ", texte);
}

char choix(FILE* page, char* line ) {
    char texte[LINE_SIZE];
    int id;
    sscanf(line, "<choice idref=\"%d\">%[^<]</choice>", &id, texte);
    fprintf(page, "<div class='Encadrement'><a href=\"%02d.html\" class=\"box\">\n <p>%s<br><strong> Effectuer ce choix</strong></p>\n </a></div>\n ", id,texte);
}
void fieldset(FILE* page,char* line ) {
    sscanf(line, "<fieldset ></fieldset>");
        fprintf(page, "<fieldset> <iframe src=""https://gifer.com/embed/bAU"" allowFullScreen></iframe><p><a href=""https://gifer.com""></a></p></fieldset>\n</body>\n</html>\n ");
    }
