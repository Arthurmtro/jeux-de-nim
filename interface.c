#include "interface.h"

// Affiche une ligne de batonnets
void afficher_batonnets(short nbr_batonnets, char* tab) {
    for (short i = 0; i < nbr_batonnets; i++) {
        printf(" ");  // Espace vide devant
        if (tab[i] == '1')
            printf("\x1b[42m \x1b[0m");  // Batonnet present, dessiner en vert
        else
            printf("\x1b[41m \x1b[0m");  // Batonnet absent, dessiner en rouge
        printf(" ");                     // Espace vide derriere
    }
}

// Affiche le plateau de jeu
void afficher_plateau(short nbr_batonnets, char* tab) {
    char car = 'A';

    // Bord du haut
    printf("\n\t");
    for (short i = 0; i < 3 * nbr_batonnets + 2; i++) printf("=");
    printf("\n");

    // Ligne du haut
    printf("\t|");
    for (short i = 0; i < 3 * nbr_batonnets; i++) printf(" ");
    printf("|");
    printf("\n");

    // Lignes avec batonnets de 8 de haut
    for (short i = 0; i < 8; i++) {
        printf("\t|");
        afficher_batonnets(nbr_batonnets, tab);
        printf("|");
        printf("\n");
    }

    // Ligne du bas
    printf("\t|");
    for (short i = 0; i < 3 * nbr_batonnets; i++) printf(" ");
    printf("|");
    printf("\n");

    // Bord du bas
    printf("\t");
    for (short i = 0; i < 3 * nbr_batonnets + 2; i++) printf("=");
    printf("\n");

    // Afficher lettres
    printf("\t ");  // Espace vide avant
    for (short i = 0; i < nbr_batonnets; i++) {
        printf(" ");  // Espace avant
        printf("%c", car + i);
        printf(" ");  // Espace après
    }
    printf(" ");  // Espace vide apres
}

void afficher_menu(short id_joueur, short echec) {
    printf("\n\n\n\n\n");  // Separer le menu du plateau

    // Afficher numero du joueur
    if (id_joueur == 1)
        printf("\tJoueur : 1\n");
    else
        printf("\tJoueur : 2\n");
    printf("\t-----------\n");

    // Afficher message
    if (!echec)
        printf("\tBatonnets [A-T] ? : ");
    else
        printf("\tSaisie eronnee, recommencer\n\tBatonnets [A-T] ? : ");
}

void afficher_jeu(short nbr_batonnets, char* tab, short id_joueur,
                  short echec) {
    printf("\33c\e[3J");  // Clear la console
    printf(
        "               ___                       _        _   _ _           "
        "\n  "
        "          "
        "  |_  |                     | |      | \\ | (_)          \n          "
        "      | | ___ _   ___  __   __| | ___  |  \\| |_ _ __ ___  \n         "
        "       | |/ _ \\ | | \\ \\/ /  / _` |/ _ \\ | . ` | | '_ ` _ \\ \n    "
        "        /\\__/ /  __/ |_| |>  <  | (_| |  __/ | |\\  | | | | | | |\n  "
        "          \\____/ \\___|\\__,_/_/\\_\\  \\__,_|\\___| \\_| \\_/_|_| "
        "|_| |_|\n            \n            \n");

    afficher_plateau(nbr_batonnets, tab);  // Afficher le plateau
    afficher_menu(id_joueur, echec);
}

void afficher_fin(short id_joueur, short nb_tours) {
    printf("\33c\e[3J");  // Clear la console
    printf(
        " _   _ _____ _____ _____ _____ ___________ _____ \n| | | |_   _/  __ "
        "\\_   _|  _  |_   _| ___ \\  ___|\n| | | | | | | /  \\/ | | | | | | | "
        "| "
        "| |_/ / |__  \n| | | | | | | |     | | | | | | | | |    /|  __| "
        "\n\\ \\_/ /_| |_| \\__/\\ | | \\ \\_/ /_| |_| |\\ \\| |___ \n \\___/ "
        "\\___/ \\____/ \\_/  \\___/ \\___/\\_| \\_\\____/ \n");

    printf(
        "\n\n\n\t|Fin de la partie !\n\t|Victoire du joueur %d en %d tours !",
        id_joueur, nb_tours);

    printf("\n\n\tRecommencer ? y/n\n\t");
}

void menu_principal(void) {
    printf("\33c\e[3J");  // Clear la console

    printf(
        "               ___                       _        _   _ _           "
        "\n  "
        "          "
        "  |_  |                     | |      | \\ | (_)          \n          "
        "      | | ___ _   ___  __   __| | ___  |  \\| |_ _ __ ___  \n         "
        "       | |/ _ \\ | | \\ \\/ /  / _` |/ _ \\ | . ` | | '_ ` _ \\ \n    "
        "        /\\__/ /  __/ |_| |>  <  | (_| |  __/ | |\\  | | | | | | |\n  "
        "          \\____/ \\___|\\__,_/_/\\_\\  \\__,_|\\___| \\_| \\_/_|_| "
        "|_| |_|\n");

    printf("\n© Monteiro Arthur & Beaugas Antoine");

    printf("\n\n\n\t1 : Lancer une parti\n\t2 : Quitter\n\t");
}