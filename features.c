#include "features.h"

void init_tab(char *tab, int taille_tab) {
    for (short i = 0; i < taille_tab; i++) {
        tab[i] = '1';
    }
}

int is_empty(char *tab, int taille_tab) {
    for (short i = 0; i < taille_tab; i++) {
        if (tab[i] == '1') return 0;
    }

    // Si aucun 1 n'est rencontré, alors il n'y a plus de batonnets
    return 1;
}

short saisie_joueur(short id_joueur, char output[4], char tab[20]) {
    // 3 est le max de batonnets que le joueur peut enlever
    char saisie[4] = "000";

    // clear ouput
    for (short i = 0; i < 4; i++) {
        output[i] = '0';
    }

    scanf("%s", saisie);

    for (int i = 0; i < 3 && saisie[i] != '\0'; i++) {
        // Si la saisie est en minuscule, on l'a met en maj
        if (saisie[i] >= 97 && saisie[i] <= 122) {
            saisie[i] -= 32;
        }

        if (saisie[i] < 65 || saisie[i] > 65 + 20) {
            // Erreur lors de la saisie
            return 1;
        }

        // Si le batonnet est deja enleve c'est une erreur.
        if (tab[saisie[i] - 65] == '0') {
            return 1;
        }

        output[i] = saisie[i];
    }

    // Si le joueur entre 4 value, c'est une erreur.
    if (saisie[3] != '\0') {
        return 1;
    }

    return 0;
}

void enlever_batonnet(char tab[20], char choix_joueur[3]) {
    for (short idx = 0; idx < 3; idx++) {
        int ascii = (int)choix_joueur[idx];

        int idxToRemove = ascii - 65;

        tab[idxToRemove] = '0';
    }
}