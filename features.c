#include "features.h"

void init_tab(char *tab, int taille_tab) {
    // Init tab with all value to "1"
    for (short i = 0; i < taille_tab; i++) {
        tab[i] = '1';
    }
}

int is_empty(char *tab, int taille_tab) {
    // if tab is full of zero, it mean it's empty
    for (short i = 0; i < taille_tab; i++) {
        // printf("tab[%d] = %c \n", i, tab[i]);

        if (tab[i] == '1') {
            return 0;
        }
    }

    // Si aucun 1 n'est rencontré, alors il n'y a plus de batonnets
    return 1;
}

short saisie_joueur(short id_joueur, char output[4]) {
    char saisie[4] =
        "000";  // 3 est le max de batonnets que le joueur peut enlever
    scanf("%c %c %c", &saisie[0], &saisie[1], &saisie[2]);

    for (int i = 0; i < 3; i++) {
        if (saisie[i] < 65 || saisie[i] > 90) {
            return 1;  // Erreur lors de la saisie
        }

        output[i] = saisie[i];
    }

    return 0;
}

int enlever_batonnet(char tab_batonnets[20], char choix_joueur[3]) {
    for (short idx = 0; idx < 3; idx++) {
        int ascii = (int)choix_joueur[idx];

        int idxToRemove = ascii - 65;

        printf("val = %c \n", choix_joueur[idx]);

        printf("ascii = %d \n", ascii);

        printf("idxToRemove = %d \n", idxToRemove);

        tab_batonnets[idxToRemove] = '0';
    }

    return 0;
}