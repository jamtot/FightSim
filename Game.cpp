#include "Game.h"
#include <stdlib.h>

void Game::init() {
	char even, hOrT;
	int health;
	int attack;

	//ask for whether the fight is even
	cout << "Welcome to the big fight. ";
	do {
	cout << "Will it be an even one? Y or N ";
	cin >> even;
	} //if the player doesn't input a y or n, ask again. 
	while ( (even != 'N') && (even != 'n') &&
		(even != 'Y') && (even != 'y') );
	
	//if yes, take the values that will be applied to both and apply
	if ( (even == 'Y') || (even == 'y') ) {
		
		cout << "\n\nFair it is. How much health do the players have? ";
		cin >> health;
		cout << "\n\nOkay, so both contestants have " << health << " health, now how much should an attack take? ";
		cin >> attack;

		mPlayer.init(health, attack);
		mComputer.init(health, attack);

		cout << "Okay, so the fighters are prepped. A landed strike will take " << attack << " health from the opposing player." << endl;

	} else {//if the match is uneven, take in the values seperately

		cout << "Unfair, is it? Alrighty. How much health do you want your fighter to have? ";
		cin >> health;
		cout << "\n\nAnd how much damage will your attack cause? ";
		cin >>attack;
		
		mPlayer.init(health, attack);
		cout << "\n\nSo you have " << health << " health, and " << attack << " attack. What health do I get? ";
		cin >> health;
		
		//gotta have the computer intimidate the player
		if (health < mPlayer.getHealth()) {
			cout << "\nOh you're giving me less? Thanks buddy.\n";
		} else {
			cout << "\nOh you think I'm that easy? Huh?\n";
		}

		cout << "So how much do my attacks land on you? ";
		cin >> attack;
		
		//do you even lift?
		if (attack < mPlayer.getHitStrength() ) {
			cout << "\nYou're making me weaker? I lift, bro. Do you even lift?\n";
		} else { 
			cout << "\nThat's right. I lift, bro\n";
		}

		mComputer.init(health, attack);
	}
	//Players now set up.

	//TODO
	// 1. DONE! Flip a coin to see who attacks first.
	// 2. Take attack/block from each player (high, mid, low).
	// 3. If blocked, attack does no damage, if not blocked, take damage.
	// 4. If attack countered successfully, attacking player takes damage, if not successfully countered, blocking player takes extra damage.
	// 5. Rinse and repeat until someone has health > 1.
	// 6. Game is overm collect your winnings and go home.
	
	cout << "A coin will be flipped to determine who starts, do you want heads or tails? Enter H or T: ";

	do {	
	cin >> hOrT;
	} while (hOrT != 'H' && hOrT != 'h' && hOrT != 'T' && hOrT != 't');

	int pChose, coin;

	if (hOrT == 'H' || hOrT == 'h') {	
		cout << "\nYou chose heads.\n"; pChose = 0; 
	} else { 
		cout << "\nYou chose tails.\n"; pChose = 1; 
	}
	srand(time(NULL));
	coin = (rand() % 2);//this will give the remainder of a division by two, so either 0 or 1.
	
	if (coin == 0) {
		cout << "Heads!\n";
	} else {
		cout << "Tails!\n";
	}

	if (coin == pChose) {
		cout << "You got it, you will go first.\n";
		playerTurn = true;
	} else {
		cout <<"I got it, I'll go first.\n";
		playerTurn = false;
	}
}
void Game::loop(){}
