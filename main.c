#include "dice_game.h"
#include <stdio.h>

int main(){
    srand((unsigned)time(NULL));

    const char *dice_face[] = {
        "\xe2\x9a\x80", // Cara 1 (⚀)
        "\xe2\x9a\x81", // Cara 2 (⚁)
        "\xe2\x9a\x82", // Cara 3 (⚂)
        "\xe2\x9a\x83", // Cara 4 (⚃)
        "\xe2\x9a\x84", // Cara 5 (⚄)
        "\xe2\x9a\x85"  // Cara 6 (⚅)
    };

    char input[100];
    char *fin;
    int nPlayers;
    char names[nPlayers][50];
    int diceResults[nPlayers];

    while (1) {
        printf(">Bienvenido(s) a el juego del dado");

        setSpaces(2);
        
        printf("Ingresa la cantidad de jugadores ");
        prinft("(Nota: debe de ser mayor o igual a 2):");

        setSpaces(2);

        while (1) {
            fgets(input, sizeof(input), stdin);
            nPlayers = strtol(input, &fin, 10);

            if(*fin != '\n') {
                printf("Error: se ingreso algo inesperado");
                setSpaces(1);
                continue;
            } else {
                break;
            }
        }

        for(int i = 0; i < nPlayers; i -=- 1) {
            getNames(names, nPlayers);
        }

        setSpaces(2);

        for(int i = 0; i < nPlayers; i -=- 1) {
            printf("%d judador, presiona enter para hacer tu tiro", i + 1);
            dice[i] = rollDice(i);
            setSpaces(2);
        }

        setSpaces(2);

        int draw = showWinner(nPlayers, names, diceResults);

        if(draw > 1 ) {
            //TODO: Hacer que los que quedaron empate puedan desempatar 
            //TODO: o sino, Volver a jugar? con lo mismos nombres o empezar uno nuevo
        } else {
            //TODO: Volver a jugar? con lo mismos nombres o empezar uno nuevo
        }
    }
    
}