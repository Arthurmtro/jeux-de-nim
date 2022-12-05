#include "features.h"
#include "interface.h"
#include "stdio.h"

#define NB_BATONNETS 20

int main() {
    while (1) {
        // Affichage du menu principal
        menu_principal();

        // Choix du menu
        char choix_menu = '0';
        scanf("%c", &choix_menu);

        switch (choix_menu) {
            case '1': {
                // Si le choix est 0, alors on lance le jeu
                // Boucle de jeu
                while (1) {
                    short echec = 0;

                    // Index du tour actuel
                    short nb_tours = 0;
                    // Initialisation du nbr de batonnets au debut
                    char tab_batonnets[NB_BATONNETS];

                    init_tab(tab_batonnets, NB_BATONNETS);

                    // Init du joueur actuel
                    // 1: Player 1
                    // 2: Player 2
                    short id_joueur = 1;

                    // Boucle de jeu
                    while (!is_empty(tab_batonnets, NB_BATONNETS)) {
                        printf("\33c\e[3J");

                        afficher_jeu(NB_BATONNETS, tab_batonnets, id_joueur,
                                     echec);

                        // Input du joueur x
                        char choix_joueur[4];

                        echec = saisie_joueur(id_joueur, choix_joueur,
                                              tab_batonnets);

                        if (echec) continue;

                        // Actualisation des datas
                        enlever_batonnet(tab_batonnets, choix_joueur);

                        // Changement de joueur
                        if (id_joueur % 2 == 0) {
                            id_joueur = 1;
                        } else {
                            id_joueur = 2;
                        }

                        // Incrementation du tour
                        nb_tours++;
                    }

                    if (is_empty(tab_batonnets, NB_BATONNETS)) {
                        // Demande de rejouer si la fin
                        afficher_fin(id_joueur, nb_tours);

                        char relance;
                        scanf(" %c", &relance);

                        if (relance == 'y' || relance == 'Y') {
                            continue;
                        } else {
                            break;
                        }
                    }
                }
            }
            case '2': {
                // Quitter le jeu
                return 0;
            }
            default: {
                // Erreur de saisie
                printf("Erreur de saisie, veuillez recommencer.\n");
                continue;
            }
        }
    }
    return 0;
}