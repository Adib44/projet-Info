#include <stdio.h>
#include <stdlib.h>

void create_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur création de %s\n", filename);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("%s créé \n", filename);
}

int main() {
    create_file("01.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 1</title></head>\n<body>\n"
        "<h1>Le Village de Grinheim</h1>\n"
        "<p>Vous êtes originaire du village de Grinheim, un endroit tranquille niché entre des collines verdoyantes et une forêt dense. Le village, autrefois prospère, se trouve aujourd'hui sous l'emprise d'une malédiction ancienne. Les récoltes pourrissent, les enfants tombent malades, et un sentiment d'oppression envahit l'air. Selon la légende, un artefact puissant, le Collier aux Sept Pierres, possède le pouvoir de briser la malédiction et de sauver Grinheim.</p>\n"
        "<p>Cette légende a traversé les générations, mais personne n'a osé se lancer à sa recherche. C’est vous qui allez tenter de briser ce cycle de malheur. Vous partez à l’aube, votre sac de voyage prêt, les premiers rayons du soleil caressant la terre. Vous avez entendu que le collier se trouve quelque part au-delà de la Forêt de Bois-Perdu, un endroit que peu de gens osent traverser.</p>\n"
        "<p>Le vent frais souffle à travers les arbres, vous donnant un dernier souffle de courage. Vous faites vos adieux aux habitants de Grinheim et prenez le chemin de l’aventure.</p>\n"
        "<a href=\"02.html\">Suivre le chemin au sud, qui mène à la Forêt de Bois-Perdu (Chapitre 2)</a><br/>\n"
        "<a href=\"03.html\">Vous dirigez vers l’Est, où un ancien château a été aperçu par les voyageurs (Chapitre 3)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("02.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 2</title></head>\n<body>\n"
        "<h1>La Forêt de Bois-Perdu</h1>\n"
        "<p>Vous entrez dans la Forêt de Bois-Perdu, un endroit sinistre et mystérieux. Les arbres s’élèvent comme des géants, leurs branches entrelacées formant un plafond presque imperméable à la lumière. Le sol est recouvert de mousse épaisse, et l’air est chargé d’humidité et d’une magie ancienne qui semble vous envelopper.</p>\n"
        "<p>Chaque bruit semble amplifié dans cette forêt. Un oiseau à la silhouette argentée s’envole à votre approche, et vous le suivez instinctivement, espérant qu’il vous guidera vers une sortie. Cependant, au bout de quelques heures de marche, vous vous rendez compte que la forêt vous a perdu. La végétation dense vous entoure, et tout semble identique.</p>\n"
        "<a href=\"03.html\">Continuer à suivre l’oiseau, espérant qu’il vous conduira à une sortie (Chapitre 3)</a><br/>\n"
        "<a href=\"04.html\">Partir vers le nord, une route qui mène apparemment vers une falaise escarpée (Chapitre 4)</a><br/>\n"
        "<a href=\"05.html\">Revenir sur vos pas, vous méfiant des ombres grandissantes dans la forêt (Chapitre 5)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("03.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 3</title></head>\n<body>\n"
        "<h1>L’Est de la Forêt et le Château</h1>\n"
        "<p>Après un long chemin, vous apercevez finalement une lueur au loin. La végétation se fait moins dense, et vous arrivez dans une clairière où se dresse un château imposant, presque en ruines. Les murs de pierres sont couverts de lichen, et les fenêtres brisées semblent observer vos moindres faits et gestes.</p>\n"
        "<p>Le vent souffle fort, apportant un frisson glacé. Vous avancez prudemment vers la porte principale, qui grince lorsqu’elle s’ouvre sous vos doigts. À l’intérieur, l’air est lourd et poussiéreux, mais vous sentez qu’un étrange pouvoir émane de ce lieu.</p>\n"
        "<p>Dans une salle sombre, vous apercevez un éclat de lumière. Vous vous approchez prudemment, mais le château semble se refermer sur vous.</p>\n"
        "<a href=\"06.html\">Explorer l’intérieur du château, à la recherche de l’artefact (Chapitre 6)</a><br/>\n"
        "<a href=\"09.html\">Chercher à ouvrir la porte du château pour sortir de ce lieu maudit (Chapitre 9)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("04.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 4</title></head>\n<body>\n"
        "<h1>Au Nord de la Forêt</h1>\n"
        "<p>Le vent du nord est glacial, et le ciel s’assombrit rapidement. Vous suivez un chemin étroit bordé de rochers escarpés, jusqu'à ce que vous atteigniez une crête où la vue est magnifique. La vallée en contrebas s’étend, serpentée par une rivière cristalline. Cependant, l’instabilité du sol rend chaque pas incertain.</p>\n"
        "<p>Une soudaine bourrasque vous fait trébucher. Vous perdez l’équilibre et, en une fraction de seconde, vous êtes projeté dans le vide. Le vent hurle à vos oreilles, et la chute est rapide. Vous heurtez les rochers sur le chemin avant de vous écraser dans la vallée.</p>\n"
        "<a href=\"09.html\">Vous êtes inconscient (Chapitre 9)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("05.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 5</title></head>\n<body>\n"
        "<h1>Le Retour au Point de Départ</h1>\n"
        "<p>Vous reprenez conscience, mais tout semble déformé. Les arbres, les rochers, tout semble revenir à son point de départ. Vous marchez sans but, jusqu’à ce que vous réalisiez que la forêt se referme encore sur vous. Le vent qui souffle ici semble plus fort, plus oppressant, et vous vous trouvez de nouveau sur le même chemin.</p>\n"
        "<p>Cela vous semble une éternité depuis que vous avez quitté Grinheim. La forêt vous piège dans un cycle sans fin. Vous vous sentez perdu, sans espoir.</p>\n"
        "<a href=\"02.html\">Continuer à avancer, espérant que le chemin finira par s’ouvrir (Chapitre 2)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("06.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 6</title></head>\n<body>\n"
        "<h1>Le Château et le Monstre</h1>\n"
        "<p>Vous pénétrez plus profondément dans le château, la lumière de votre torche projetant des ombres inquiétantes sur les murs. Une lourde porte en fer se trouve devant vous, et à l’intérieur, vous apercevez une silhouette massive : un monstre fait de chair et de pierre, ses yeux brillants comme des gemmes.</p>\n"
        "<p>Il garde l’accès à une salle secrète, sans doute celle qui abrite le Collier aux Sept Pierres. Vous êtes seul face à lui, et le combat semble inévitable. Le monstre rugit, faisant trembler les murs du château.</p>\n"
        "<a href=\"07.html\">Affronter le monstre, espérant que vos compétences de combattant suffiront à le vaincre (Chapitre 7)</a><br/>\n"
        "<a href=\"08.html\">Chercher un moyen de contourner le monstre et d’accéder à la salle secrète sans le combattre (Chapitre 8)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("07.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 7</title></head>\n<body>\n"
        "<h1>Le Combat avec le Monstre</h1>\n"
        "<p>Vous engagez le combat contre la créature, frappant de toute votre force. Mais la peau de pierre du monstre est presque imperméable. Ses attaques sont puissantes, et chaque coup vous fait chanceler. Une vague de magie noire vous submerge et vous n’avez aucune chance de vous en sortir.</p>\n"
        "<a href=\"09.html\">Vous vous effondrez, victime de cette créature terrifiante (Chapitre 9)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("08.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 8</title></head>\n<body>\n"
        "<h1>Le Collier aux Sept Pierres</h1>\n"
        "<p>Vous décidez de ne pas affronter directement le monstre, mais d’utiliser votre intelligence pour contourner le danger. Vous réussissez à atteindre la salle secrète et là, sur un piédestal de marbre, repose le Collier aux Sept Pierres. Une lumière douce émane de lui, et, sans hésiter, vous le saisissez.</p>\n"
        "<p>Le monstre, inerte, ne semble plus pouvoir vous nuire. Vous avez gagné. Vous prenez le collier et vous vous sentez empli d’un pouvoir immense.</p>\n"
        "<a href=\"10.html\">Vous prenez le collier, empli d’un pouvoir immense (Chapitre 10)</a>\n"
        "</body>\n</html>\n"
    );

    create_file("09.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 9</title></head>\n<body>\n"
        "<h1>La Mort de l'Aventurier</h1>\n"
        "<p>Quoi que vous ayez choisi, votre aventure se termine tragiquement ici. La forêt, le château et ses secrets ont eu raison de vous. Dans l’ombre de ces lieux, votre histoire prend fin. Grinheim attendra un sauveur, mais ce ne sera pas vous.</p>\n"
        "</body>\n</html>\n"
    );

    create_file("10.html",
        "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>Chapitre 10</title></head>\n<body>\n"
        "<h1>Le Collier aux Sept Pierres</h1>\n"
        "<p>Vous avez trouvé ce que vous cherchiez. Le Collier aux Sept Pierres brille dans vos mains, et avec lui, vous sentez que la malédiction qui pèse sur Grinheim va enfin être levée. Votre mission est accomplie. Vous n’êtes plus simplement un aventurier, mais un héros qui revient avec le pouvoir de sauver son village.</p>\n"
        "</body>\n</html>\n"
    );

    return 0;
}
