#ifndef DICE_GAME_H
#define DICE_GAME_H

int rollDice(int n);
void getNames(char names[][50], int nPlayers);
void setSpaces(int amount);
int showWinner(int nPlayers, char names[][50],int diceResults[]);

#endif