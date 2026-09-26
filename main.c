#include "dice_game.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    system("chcp 65001 > nul");
    srand((unsigned)time(NULL));

    char input[100];
    char *fin;
    int nPlayers;

    printf(">Bienvenido(s) a el juego del dado");

    SetSpaces(2);
        
    nPlayers = AmountPeople();

    char names[nPlayers][50];
    int diceResults[nPlayers];
    char drawPlayers[nPlayers][50];

    GetNames(names, nPlayers);

    SetSpaces(2);

    while (1) {
        for(int i = 0; i < nPlayers; i -=- 1) {
            printf("%s, presiona enter para hacer tu tiro", names[i]);
            getchar();
            diceResults[i] = RollDice(i);
            printf("%s sacó %s (%d)", names[i], GetDiceFace(diceResults[i]), diceResults[i]);
            SetSpaces(2);
        }

        SetSpaces(2);

        int draw = ShowWinner(nPlayers, names, diceResults, drawPlayers);

        while (1) {
            if(draw > 1 ) {
                    printf("Desempatar? (Y/n): ");
                    fgets(input, sizeof(input), stdin);

                    if((input[0] == 'Y' || input[0] == 'y') && strlen(input) <= 2) {
                        memset(diceResults, 0, sizeof(diceResults));
                        for(int i = 0; i < draw; i -=- 1) {
                            printf("%s, presiona enter para hacer tu tiro", drawPlayers[i]);
                            getchar();
                            diceResults[i] = RollDice(i);
                            printf("%s sacó %s (%d)", drawPlayers[i], GetDiceFace(diceResults[i]), diceResults[i]);
                            SetSpaces(2);
                        }
                        draw = ShowWinner(nPlayers, names, diceResults, drawPlayers);
                        break;
                    }
            } else {
                break;
            }

            if ((input[0] == 'N' || input[0] == 'n') && strlen(input) <= 2) {
                break;
            } else {
                printf("Error: Esa opcion no existe!");
                SetSpaces(2);
            }
        }

        while (1) {
            printf("Cerrar juego? (Y/n): ");
            fgets(input, sizeof(input), stdin);

            if((input[0] == 'Y' || input[0] == 'y') && strlen(input) <= 2) return 0;
            if((input[0] == 'N' || input[0] == 'n') && strlen(input) <= 2) {
                if(PlayAgain()) {
                    system("cls");
                    break;
                } else {
                    nPlayers = AmountPeople();
                    GetNames(names, nPlayers);
                    break;
                }
            } else {
                printf("Error: Esa opcion no existe!");
                SetSpaces(2);
            }
        }
    }
    
}