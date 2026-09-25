#ifndef DICE_GAME_H
#define DICE_GAME_H

int RollDice(int n);
void GetNames(char names[][50], int nPlayers);
void SetSpaces(int amount);
int ShowWinner(int nPlayers, char names[][50],int diceResults[]);

#endif