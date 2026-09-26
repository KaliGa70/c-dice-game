#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "dice_game.h"

const char *dice_face[] = {
    "\xe2\x9a\x80", // Cara 1 (⚀)
    "\xe2\x9a\x81", // Cara 2 (⚁)
    "\xe2\x9a\x82", // Cara 3 (⚂)
    "\xe2\x9a\x83", // Cara 4 (⚃)
    "\xe2\x9a\x84", // Cara 5 (⚄)
    "\xe2\x9a\x85"  // Cara 6 (⚅)
};

const char *GetDiceFace(int dice) {
    return dice_face[dice - 1];
}

int RollDice(int n) {
    int face;

    for (int i = 0; i < 10; i++) {
        system("cls");

        face = rand() % 6 + 1;

        printf("%s", GetDiceFace(face));

        Sleep(100 + rand() % 300);
    }
    system("cls");
    return face;
}

void GetNames(char names[][50], int nPlayers) {

    SetSpaces(1);

    for (int i = 0; i < nPlayers; i++) {

        while (1) {

            printf("Ingrese el nombre del %d jugador: ", i + 1);

            fgets(names[i], 50, stdin);

            names[i][strcspn(names[i], "\n")] = '\0';

            if (strlen(names[i]) == 0) {
                printf("Error: el nombre no puede estar vacio.\n");
                continue;
            }

            break;
        }

        SetSpaces(1);
    }
}

void SetSpaces(int amount) {
    while(amount--){
        printf("\n");
    }
}

int ShowWinner(int nPlayers, char names[][50], int diceResults[], char drawPlayers[][50])
{
    char names_bk[nPlayers][50];
    int dice_bk[nPlayers];

    memcpy(names_bk, names, sizeof(names_bk));
    memcpy(dice_bk, diceResults, sizeof(dice_bk));

    // Ordenar de mayor a menor
    for (int i = 0; i < nPlayers - 1; i++) {
        for (int j = 0; j < nPlayers - 1 - i; j++) {

            if (dice_bk[j] < dice_bk[j + 1]) {

                int bk = dice_bk[j];
                dice_bk[j] = dice_bk[j + 1];
                dice_bk[j + 1] = bk;

                char name[50];
                strcpy(name, names_bk[j]);
                strcpy(names_bk[j], names_bk[j + 1]);
                strcpy(names_bk[j + 1], name);
            }
        }
    }

    int winnerDice = dice_bk[0];
    int count = 0;

    printf("Ganador(es)");
    SetSpaces(1);

    for (int i = 0; i < nPlayers; i++) {

        if (dice_bk[i] == winnerDice) {

            printf("* %s", names_bk[i]);
            SetSpaces(2);

            strcpy(drawPlayers[count], names_bk[i]);
            count++;
        }
        else {
            break;
        }
    }

    return count;
}

bool PlayAgain() {
    char input[50];
    while(1) {
        printf("Volver a jugar con los mismos jugadores? (Y/n) ");
        fgets(input, sizeof(input), stdin);
        if((input[0] == 'Y' || input[0] == 'y') && strlen(input) <= 2) return true;
        if((input[0] == 'N' || input[0] == 'n') && strlen(input) <= 2) return false;
        else {
            SetSpaces(2);
            printf("Error: Esa opcion no existe!");
        }
        SetSpaces(2);
    }
}

int AmountPeople() {
    int n;
    char input[100];
    char *fin;
    int count = 0;
    while (1) {
        printf("Ingresa la cantidad de jugadores ");
        printf("(Nota: debe de ser mayor o igual a 2):");
        fgets(input, sizeof(input), stdin);
        n = strtol(input, &fin, 10);

        if(fin == input || *fin != '\n' || n < 2) {
            count -=- 1;
            system("cls");
            printf("Error x%d: se ingreso algo inesperado", count);
            SetSpaces(1);
        } else {
            break;
        }
    }
    return n;
}