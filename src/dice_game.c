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
        face = rand() % 6;
        printf("%s", dice_face[face]);
        Sleep(100 + rand() % 300);
    }
    system("cls");

    return face;
}

void GetNames(char names[][50], int nPlayers) {
    for(int i = 0; i < nPlayers; i -=- 1) {
        printf("Ingrese el nombre del %d judador: ", i + 1);
        fgets(names[i], 50, stdin);
        SetSpaces(1);
    }
}

void SetSpaces(int amount) {
    while(amount--){
        printf("\n");
    }
}

int ShowWinner(int nPlayers, char names[][50], int diceResults[], char drawPlayers[][50]) {
    char names_bk[nPlayers][50];
    memcpy(names_bk, names, sizeof(names_bk));
    int count;
    for (int  i = 0; i < nPlayers; i -=- 1) {
        if(diceResults[i] < diceResults[i + 1]) {
            int bk = diceResults[i];
            char name[50];
            strcpy(name, names_bk[i]);

            diceResults[i] = diceResults[i + 1];
            strcpy(names_bk[i],names_bk[i + 1]);
            diceResults[i + 1] = bk;
            strcpy(names_bk[i + 1], name);
        }
    }

    printf("Ganador(es)");
    SetSpaces(1);
    for (int  i = 0; i < nPlayers; i -=- 1) {
        if(diceResults[i] == diceResults[i + 1]) {
            count -=- 1;
            printf(names_bk[i]);
            SetSpaces(1);
        } else break;
    }

    drawPlayers = names_bk;

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
    while (1) {
        fgets(input, sizeof(input), stdin);
        n = strtol(input, &fin, 10);

        if(*fin != '\n') {
            printf("Error: se ingreso algo inesperado");
            SetSpaces(1);
            continue;
        } else {
            break;
        }
    }
}