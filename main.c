

#include "features.h"
#include "interface.h"
#include "stdio.h"

#define NB_BATONNETS 20

int main() {
    // Boucle de jeu
    while (1) {
        // Index du tour actuel
        int nb_tours = 0;
        // Initialisation du nbr de batonnets au debut
        char tab_batonnets[NB_BATONNETS];

        init_tab(tab_batonnets, NB_BATONNETS);

        // Init du joueur actuel
        // 1: Player 1
        // 2: Player 2
        short id_joueur = 1;

        // Boucle de jeu
        while (!is_empty(tab_batonnets, NB_BATONNETS)) {
            // printf("\e[1;1H\e[2J");

            short echec = 0;

            afficher_jeu(NB_BATONNETS, tab_batonnets, id_joueur, echec);

            // Input du joueur x

            char choix_joueur[4];

            echec = saisie_joueur(id_joueur, choix_joueur);

            // if (echec) continue;

            // Actualisation des datas

            enlever_batonnet(tab_batonnets, choix_joueur);

            // Changement de joueur

            // Incrementation du tour

            nb_tours++;

            // Clear de la console
        }

        break;
    }

    return 0;
}