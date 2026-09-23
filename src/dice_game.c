#include "dice_game.h"

const char *dice_face[] = {
    "\xe2\x9a\x80", // Cara 1 (⚀)
    "\xe2\x9a\x81", // Cara 2 (⚁)
    "\xe2\x9a\x82", // Cara 3 (⚂)
    "\xe2\x9a\x83", // Cara 4 (⚃)
    "\xe2\x9a\x84", // Cara 5 (⚄)
    "\xe2\x9a\x85"  // Cara 6 (⚅)
};

int rollDice(int n) {
    int face;

    for (int i = 0; i < 10; i++) {
        system("cls");
        face = rand() % 6;
        printf("%s", dice_face[face]);
        Sleep(100 + rand() % 300);
    }
    system("cls");
    printf("%d jugador sacó %s", n, dice_face[face]);

    return face;
}

void getNames(char names[][50], int nPlayers) {
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

int showWinner(int nPlayers, char names[][50], int diceResults[]) {
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

    return count;
}