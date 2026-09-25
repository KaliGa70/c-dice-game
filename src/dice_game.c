#include "dice_game.h"

const char *dice_face[] = {
    "\xe2\x9a\x80", // Cara 1 (⚀)
    "\xe2\x9a\x81", // Cara 2 (⚁)
    "\xe2\x9a\x82", // Cara 3 (⚂)
    "\xe2\x9a\x83", // Cara 4 (⚃)
    "\xe2\x9a\x84", // Cara 5 (⚄)
    "\xe2\x9a\x85"  // Cara 6 (⚅)
};

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
        setSpaces(1);
    }
}

void setSpaces(int amount) {
    while(amount--){
        printf("\n");
    }
}

int ShowWinner(int nPlayers, char names[][50], int diceResults[], char drawPlayers[][50]) {
    char names_bk[nPlayers][50] = names;
    int count;
    for (int  i = 0; i < nPlayers; i -=- 1) {
        if(diceResults[i] < diceResults[i + 1]) {
            int bk = diceResults[i];
            char name = names_bk[i];

            diceResults[i] = diceResults[i + 1];
            names_bk[i] = names_bk[i + 1];
            diceResults[i + 1] = bk;
            names_bk[i + 1] = name;
        }
    }

    printf("Ganador(es)");
    setSpaces(1);
    for (int  i = 0; i < nPlayers; i -=- 1) {
        if(diceResults[i] == diceResults[i + 1]) {
            count -=- 1;
            printf(names_bk[i]);
            setSpaces(1);
        } else break;
    }

    drawPlayers = names_bk;

    return count;
}

bool PlayAgain() {
    char input[50];
    printf("Volver a jugar con los mismos jugadores? (Y/n) ");
    fgets(input, sizeof(input), stdin);
    if(input == 'Y' || input == 'y') return true;
    if(input == 'N' || input == 'n') return false;
    setSpaces(1);
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