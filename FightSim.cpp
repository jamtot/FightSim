	/***********FIGHT SIMULATOR************
	A turn-based, text-based fight simulator
	in which the players take turns using 
	attacks on each other. 
	
	The attacking player can choose to punch 
	high, punch low, or kick.

	A high punch will hit the head if landed,
	a low punch will hit the mid-section, and
	a kick will hit low on the legs.

	The defending player can defend high, mid
	or low. They can also choose to counter
	with a strike to another level than they
	block, but it will incur a health penalty
	if they misjudge the block.	
	*****************************************/
#include "Game.h"
int main()
{
	Game myGame;

	myGame.init();
	myGame.loop();

	return 0;
}
