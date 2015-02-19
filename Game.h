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
	bool playerTurn;

	void printMove(char highMidLow, bool isPlayer, bool isAttack);
	char highMidOrLow();
	bool randBool();
};

#endif
