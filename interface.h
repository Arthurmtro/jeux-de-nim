#include "stdio.h"

/*
+---------+------------+------------+
|  color  | foreground | background |
|         |    code    |    code    |
+---------+------------+------------+
| black   |     30     |     40     |
| red     |     31     |     41     |
| green   |     32     |     42     |
| yellow  |     33     |     43     |
| blue    |     34     |     44     |
| magenta |     35     |     45     |
| cyan    |     36     |     46     |
| white   |     37     |     47     |
+---------+------------+------------+

printf("\x1b[42m regular text on green background \x1b[0m  \n");

https://stackoverflow.com/questions/33309136/change-color-in-os-x-console-output

CLEAR: printf("\33c\e[3J");

ASCII: https://patorjk.com/software/taag/#p=display&f=Soft&t=Jeux%20de%20Nim
*/

/*
 * Affiche une ligne de batonents
 * @param short nombre de batonnets
 * @param *char tableau de batonnets : 0 si rien, 1 si batonnet
 */
void afficher_batonnets(short, char*);

/*
 * Affiche l'ensemble du plateau (batonnets + bords)
 * @param short nombre de batonnets
 * @param *char tableau de batonnets
 */
void afficher_plateau(short, char*);

/*
 * Affiche le menu
 * @param short id du joueur
 * @param short code d'erreur
 */
void afficher_menu(short, short);

/*
 * Affiche l'ensemble du jeu (plateau + menu)
 * @param short nombre de batonnets
 * @param char* tableau de batonnets
 * @param short id du joueur
 * @param short code d'erreur
 */
void afficher_jeu(short, char*, short, short);

/*
 * @param short id du joueur
 * @param short nombre de tours
 */
void afficher_fin(short, short);

/*
 * Affiche le menu principal
 */
void menu_principal(void);