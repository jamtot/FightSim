#include "Game.h"

void Game::init() {
	char even;
	int health;
	int attack;
	//ask for whether the fight is even
	do {
	cout << "Welcome to the big fight, will it be an even one? Y or N ";
	cin >> even;
	} //if the player doesn't input a y or n, ask again. 
	while (char != 'N' || char != 'n' ||
		char != 'Y' || char != 'y');
	
	//if yes, take the values that will be applied to both and apply
	if (char == 'Y' || char == 'y') {
		cout << "\n\nFair it is. How much health do the players have? ";
		cin >> health;
		cout << "\n\nOkay, so both contestants have " << health << " health, now how much should an attack take? ";
		cin >> attack;

		mPlayer = Fighter(health, attack);
		mComputer = Fighter(health, attack);

		cout << "Okay, so the fighters are prepped. A landed strike will take " << attack << " health from the opposing player." << endl;
	} //if the match is uneven, take in the values seperately
	else {
		cout << "Unfair, is it? Alrighty. How much health do you want your fighter to have? ";
		cin >> health;
		cout << "\n\nAnd how much damage will your attack cause? ";
		cin >>attack;
		
		mPlayer = Fighter(health, attack);
		cout << "\n\nSo you have " << health << " health, and " << attack " attack. What health do I get? ";
		cin >> health;
		
		//gotta have the computer intimidate the player
		if (health < mPlayer.getHealth()) 
			cout << "\nOh you're giving me less? Thanks buddy.\n"
		else 
			cout << "\nOh you think I'm that easy? Huh?\n"

		cout << "So how much do my attacks land on you? ";
		cin >> attack;
		
		//do you even lift?
		if (attack < mPlayer.getHitStrength() ) 
			cout << "\nYou're making me weaker? I lift, bro. Do you even lift?\n"
		else 
			cout << "\nThat's right. I lift, bro\n";

		mComputer = Fighter(health, attack);
	}
	//Players now set up.

	//TODO
	// 1. Flip a coin to see who attacks first.
	// 2. Take attack/block from each player (high, mid, low).
	// 3. If blocked, attack does no damage, if not blocked, take damage.
	// 4. If attack countered successfully, attacking player takes damage, if not successfully countered, blocking player takes extra damage.
	// 5. Rinse and repeat until someone has health > 1.
	// 6. Game is overm collect your winnings and go home.
	

	
	
}
void Game::loop(){}
