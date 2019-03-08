
#include <stdio.h>
#include <windows.h>

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
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center


//Bataille navale
//Pedro Pinto
//07.03.2019

int main() {
    printf(" .  o ..\n"
           " o . o o.o\n"
           "      ...oo\n"
           "        __[]__\n"
           "     __|_o_o_o\\__\n"
           "     \\\"\"\"\"\"\"\"\"\"\"/\n"
           "      \\. ..  . /\n"
           " ^^^^^^^^^^^^^^^^^^^^");                    // ASCII art bateau
    printf("\nVoici le jeu de la Bataille navale\n\n\n ");      //introduction
    printf("\nRegle de la Bataille navale\n"                    //REGLERS !!
           "On vous proposera une grille de jeu numerotee de 1 a 10 horizontalement et\nde A a J verticalement avec les bateaux suivants deja place.\n"
           "1 croiseur (4 cases)\n"
           "1 contre torpilleur (3 cases)\n"
           "1 torpilleur (2 cases)");
    "vous devez a present tirer sur la grile adverse et tener de toucher les bateaux adverses";
    "le premier joueur a perdre tous les batesu perd la partie";


    SetConsoleOutputCP(65001); // For accented characters
    printf("Une grille basée sur les lignes simples:\n");
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("%c", STLC);
    for (int row = 0; row < 9; row++) {
        printf("%c%c", SHSB, SHTB);
    }
    for (int row = 0; row < 9; row++) {
        printf("%c%c\n", SHSB, SVRB);
        for (int row = 0; row < 11; row++) {
            printf("%c ", SVSB);
        }
        printf("\n%c", SVLB);
        for (int row = 0; row < 9; row++) {
            printf("%c%c", SHSB, SC);
        }
    }
    printf("%c%c\n",SHSB , SBRC);
    for (int row = 0; row < 11; row++) {
        printf("%c ", SVSB);
    }
    printf("\n%c", SBLC);
    for (int row = 0; row < 9; row++) {
        printf("%c%c", SHSB, SHBB);
    }
    printf("%c%c",SHSB, SBRC);


//      printf("%c   %c   %c\n", SVSB, SVSB, SVSB);
//      printf("%c%c%c%c%c%c%c%c%c\n", SBLC, SHSB, SHSB, SHSB, SHBB, SHSB, SHSB, SHSB, SBRC);

//      SetConsoleOutputCP(65001); // For accented characters
//      printf("\n\nUne grille basée sur les lignes doubles:\n");
//      SetConsoleOutputCP(437); // For semi-graphic characters
//      printf("%c%c%c%c%c%c%c%c%c\n", DTLC, DHSB, DHSB, DHSB, DHTB, DHSB, DHSB, DHSB, DTRC);
//      printf("%c   %c   %c\n", DVSB, DVSB, DVSB);
//      printf("%c%c%c%c%c%c%c%c%c\n", DVLB, DHSB, DHSB, DHSB, DC, DHSB, DHSB, DHSB, DVRB);
//      printf("%c   %c   %c\n", DVSB, DVSB, DVSB);
//      printf("%c%c%c%c%c%c%c%c%c\n", DBLC, DHSB, DHSB, DHSB, DHBB, DHSB, DHSB, DHSB, DBRC);

//
}