#ifndef GAME_H
#define GAME_H

#include <ctime>
#include "Fighter.h"
#include <iostream>

using namespace std;

class Game {
public:
	void init();
	void loop();
private:
	Fighter mPlayer;
	Fighter mComputer;
	bool playerTurn, countersOn;

	void printMove(char highMidLow, bool isPlayer, bool isAttack);
	char highMidOrLow();
	bool randBool();
	char getPlayerMove(bool attack);
	void outcome(char pMove, char cMove, bool isPlayerMove, bool attemptCounter = false);
	char makeCharSmall(char character);
};

#endif
