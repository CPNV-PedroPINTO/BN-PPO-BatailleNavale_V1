
#include <stdio.h>
#include <windows.h>

#define SIZE 10
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define CUBE 219

int hit[5] = {0, 0, 0, 0, 0};
int grille[10][10] = {{3, 0, 0, 0, 0, 0, 0, 0, 0, 0},                   //Model
                      {3, 0, 0, 0, 5, 5, 5, 5, 5, 0},
                      {3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 2, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


void topborder(int top) {
    printf("     A   B   C   D   E   F   G   H   I   J     \n");
    printf("   %c", STLC);             //┌
    for (int row = 0; row < top - 1; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);         //9x ─┬
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, STRC);// ─┐
}

void horizontalborder(int horizon) {
    printf("   %c", SVLB);           //\n├
    for (int row = 0; row < horizon - 1; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);       //9x ─┼
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SVRB);     //─┤
}

void botborder(int bot) {
    printf("   %c", SBLC);                    //\n puis └
    for (int row = 0; row < bot - 1; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);         //─┴
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SBRC);              //─┘
}

void Verticalborder(int vertical, int num) {

    printf("%2d %c", num, SVSB);                    //\n puis └
    for (int row = 0; row < vertical; row++) {

        char carAFF = ' ';
        if (grille[num - 1][row] > 10) {
            carAFF = 'X';
        }
        if (grille[num - 1][row] > 20) {
            carAFF = CUBE;
        }
        if (grille[num - 1][row] == -1) {
            carAFF = 'O';
        }
        printf(" %c %c", carAFF, SVSB);         //─┴
    }
    printf("\n");              //─┘
}

void Playgame() {
    int test = 0;
    while (test != 1) {
        //Afficher la grille
        printf("Voila votre grille choisicez votre cible\n");
        topborder(SIZE);
        for (int row = 0; row < SIZE; row++) {          //Grille
            if (row > 0)//first line
            {
                horizontalborder(SIZE);

            }
            Verticalborder(SIZE, row + 1);

        }
        botborder(SIZE);
        //Demander le coordonées de tir
        char tir[5];
        printf("Vos bateaux sont prets faite feu ! ! !\n");
        printf("donnez-moi vos coordonnees : ");
        scanf("%s", &tir);
        int col = tir[0] - 65;
        int row = tir[1] - 49;
        int valcase = grille[row][col];

        if (valcase == 0) {
            printf("\nA l'eau\n");
            grille[row][col] = -1;
        }
        if (valcase >= 2) {
            printf("\ntouche\n");
            hit[valcase]++;
            grille[row][col] += 10;
        }
        for (int n = 1; n <= 5; ++n) {
        }
        //Appliquer le tir sur le model Bateau 2
        int x = 0;
        int y = 0;
        int compteur = 0;
        for (int bateau = 1; bateau <= 5; bateau++) {
            for (x = 0; x < SIZE; x++) {
                for (y = 0; y < SIZE; y++) {
                    if (grille[x][y] == bateau + 10) {
                        compteur++;
                    }
                }
            }
            printf("%d\n", compteur);
            if (compteur == bateau) {                //le bateau est coulé
                printf("Coule ! ! !\n");
                for (x = 0; x < SIZE; x++) {
                    for (y = 0; y < SIZE; y++) {
                        if (grille[x][y] == bateau + 10) {
                            grille[x][y] = bateau + 20;
                        }
                    }
                }
            }
        }
    }
}

//Bataille naval}
//Pedro Pinto
//07.03.2019

int main() {
    int top;
    int vertical;
    int horizon;
    int bot;
    int jouer;

    printf(
            "\n"
            "        __[]__\n"
            "     __|_o_o_o\\__\n"
            "     \\\"\"\"\"\"\"\"\"\"\"/\n"
            "      \\. ..  . /\n"
            " ^^^^^^^^^^^^^^^^^^^^");                    // ASCII art bateau
    printf("\nVoici le jeu de la Bataille navale\n\n\n ");      //introduction




    printf("Voulez vous jouer ?\n");
    printf("Tappez 1 pour lancer votre partie\n");
    printf("Tappez 2 afficher les regles et apprendre a jouer\n");
    printf("Tappez 0 pour quiter le jeu\n");
    scanf("%d", &jouer);
    switch (jouer) {
        case 1:
            Playgame();
            break;
        case 2:
            printf("\nRegle de la Bataille navale\n"                    //REGLERS !!
                   "On vous proposera une grille de jeu numerotee de 1 a 10 horizontalement et\nde A a J verticalement avec les bateaux suivants deja places.\n"
                   "1 croiseur (4 cases)\n"
                   "1 contre-torpilleur (3 cases)\n"
                   "1 torpilleur (2 cases)\n");
            printf("Vous devez a present tirer sur la grille adverse et tenter de toucher les bateaux");
            printf("Le premier joueur a eliminer tout les bateaux adverses gagne le combat");
            printf("Voici une video explicative : https://www.youtube.com/watch?v=klO6vPWPkzE\n");
            printf("Tous a vos postes de COMBAT!!\n\n");
            break;
        default:                                                        //Fin/quiter
            printf("Vous avez quiter ou mis un chiffre invalide\n");
            break;
    }

    SetConsoleOutputCP(65001); // For accented characters
    printf("\n\n\n");
    SetConsoleOutputCP(437); // For semi-graphic characters



    system("pause");
}