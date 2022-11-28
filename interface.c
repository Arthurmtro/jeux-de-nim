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
    for (short i = 0; i < 3 * nbr_batonnets + 2; i++) printf("=");
    printf("\n");

    // Ligne du haut
    printf("|");
    for (short i = 0; i < 3 * nbr_batonnets; i++) printf(" ");
    printf("|");
    printf("\n");

    // Lignes avec batonnets de 8 de haut
    for (short i = 0; i < 8; i++) {
        printf("|");
        afficher_batonnets(nbr_batonnets, tab);
        printf("|");
        printf("\n");
    }

    // Ligne du bas
    printf("|");
    for (short i = 0; i < 3 * nbr_batonnets; i++) printf(" ");
    printf("|");
    printf("\n");

    // Bord du bas
    for (short i = 0; i < 3 * nbr_batonnets + 2; i++) printf("=");
    printf("\n");

    // Afficher lettres
    printf(" ");  // Espace vide avant
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
    printf("\tBatonnets [A-T] ? : ");
}

void afficher_jeu(short nbr_batonnets, char* tab, short id_joueur,
                  short echec) {
    afficher_plateau(nbr_batonnets, tab);  // Afficher le plateau
    afficher_menu(id_joueur, echec);
}