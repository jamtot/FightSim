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
};

#endif
