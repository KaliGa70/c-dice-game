#include "dice_game.h"
#include <stdio.h>
#include <string.h>

int main(){
    srand((unsigned)time(NULL));

    char input[100];
    char *fin;
    int nPlayers;
    char names[nPlayers][50];
    int diceResults[nPlayers];
    char drawPlayers[nPlayers][50];

    printf(">Bienvenido(s) a el juego del dado");

    SetSpaces(2);
        
    printf("Ingresa la cantidad de jugadores ");
    prinft("(Nota: debe de ser mayor o igual a 2):");

    SetSpaces(2);

    nPlayers = AmountPeople();

    for(int i = 0; i < nPlayers; i -=- 1) {
        GetNames(names, nPlayers);
    }

    SetSpaces(2);

    while (1) {
        for(int i = 0; i < nPlayers; i -=- 1) {
            printf("%s, presiona enter para hacer tu tiro", names[i]);
            getchar();
            diceResults[i] = RollDice(i);
            printf("%s sacó %s", names[i], dice_face[i]);
            SetSpaces(2);
        }

        SetSpaces(2);

        int draw = ShowWinner(nPlayers, names, diceResults, drawPlayers);

        while (1) {
            if(draw > 1 ) {
                while (1) {
                    printf("Desempatar? (Y/n): ");
                    fgets(input, sizeof(input), stdin);

                    if(input == 'Y' || input == 'y') {
                        memset(diceResults, 0, sizeof(diceResults));
                        for(int i = 0; i < draw; i -=- 1) {
                            printf("%s, presiona enter para hacer tu tiro", drawPlayers[i]);
                            getchar();
                            diceResults[i] = RollDice(i);
                            printf("%s sacó %s", drawPlayers[i], dice_face[i]);
                            SetSpaces(2);
                        }
                        draw = ShowWinner(nPlayers, names, diceResults, drawPlayers);
                        break;
                    } else if (input == 'N' || input == 'n') {
                        break;
                    } else {
                        printf("Error: Esa opcion no existe!");
                        SetSpaces(2);
                    }
                }
            } else {
                break;
            }
        }

        while (1) {
            printf("Cerrar juego? (Y/n): ");
            fgets(input, sizeof(input), stdin);

            if(input == 'Y' || input == 'y') return 0;
            if(input == 'N' || input == 'n') {
                if(PlayAgain()) {
                    system("cls");
                    continue;
                } else {
                    printf("Ingresa la cantidad de jugadores ");
                    prinft("(Nota: debe de ser mayor o igual a 2):");
                    nPlayers = AmountPeople();
                    for(int i = 0; i < nPlayers; i -=- 1) {
                        GetNames(names, nPlayers);
                    }
                }
            } else {
                printf("Error: Esa opcion no existe!");
                SetSpaces(2);
            }
        }
    }
    
}