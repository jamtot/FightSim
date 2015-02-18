#ifndef GAME_H
#define GAME_H

#include <ctime>
#include "Fighter.h"

class Game {
public:
	void init();
	void loop();
private:
	Fighter mPlayer;
	Fighter mComputer;
};

#endif
