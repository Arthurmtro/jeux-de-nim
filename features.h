#include "stdio.h"

/*
 * Initialisation du tableau
 * @param *char Pointeur du tableau a initialiser
 * @param int Taille voulue du tableau
 */
void init_tab(char *tab, int taille_tab);

/*
 * Regarde si le tableau est rempli de '0'
 * @param *char Pointeur du tableau a verifier
 * @param int Taille du tableau
 * @return Status du tableau: 1 = Vide | 0 = Empli
 */
int is_empty(char *tab, int taille_tab);

/*
 * Recupere la saisie du joueur et fais les checks
 * @param short Id du joueur qui joue
 * @param char[4] Tableau pour la recuperation du choix du joueur
 * @param char[20] Tableau des batonnets
 * @return Status d'erreur: 1 = Erreur | 0 = Bon
 */
short saisie_joueur(short id_joueur, char output[4], char tab[20]);

/*
 * Soustraire du tableau les choix de l'utilisateur
 * @param char[20] Pointeur du tableau a soustraire
 * @param char[3] Tableau du choix du joueur
 */
void enlever_batonnet(char tab[20], char choix_joueur[3]);