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
*/

// Affiche une ligne de batonnets
void afficher_batonnets(short, char*);

/*
 * Affiche l'ensemble du plateau
 * tableau de batonnets : 0 si rien, 1 si batonnet
 */
void afficher_plateau(short, char*);

// Affiche le menu
void afficher_menu(short, short);

// Affiche l'ensemble du jeu
void afficher_jeu(short, char*, short, short);