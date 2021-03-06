#include "Game.h"
#include <stdlib.h>

void Game::init() {
	countersOn = false;
	char even, hOrT, counterYN;
	int health;
	int attack;
	srand(time(NULL));

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
		
		cout << "\nFair it is. How much health do the players have? ";
		cin >> health;
		cout << "\nOkay, so both contestants have " << health << " health, now how much should an attack take? ";
		cin >> attack;

		mPlayer.init(health, attack);
		mComputer.init(health, attack);

		cout << "\nOkay, so the fighters are prepped. A landed strike will take " << attack << " health from the opposing player.\n" << endl;

	} else {//if the match is uneven, take in the values seperately

		cout << "\nUnfair, is it? Alrighty. How much health do you want your fighter to have? ";
		cin >> health;
		cout << "\nAnd how much damage will your attack cause? ";
		cin >>attack;
		
		mPlayer.init(health, attack);
		cout << "\nSo you have " << health << " health, and " << attack << " attack. What health do I get? ";
		cin >> health;
		
		//gotta have the computer intimidate the player
		if (health < mPlayer.getHealth()) {
			cout << "\nOh you're giving me less? Thanks buddy.\n";
		} else {
			cout << "\nOh you think I'm that easy? Huh?\n";
		}

		cout << "\nSo how much do my attacks land on you? ";
		cin >> attack;
		
		//do you even lift?
		if (attack < mPlayer.getHitStrength() ) {
			cout << "\nYou're making me weaker? I lift, bro. Do you even lift?\n";
		} else { 
			cout << "\nThat's right. I lift, bro\n";
		}

		mComputer.init(health, attack);

		
	}

	cout << "\nCan we counter attack? (Y/N)";
	do { cin >> counterYN; } while ( (counterYN != 'y') && (counterYN != 'Y') && (counterYN != 'n') && (counterYN != 'N') );
	counterYN = makeCharSmall(counterYN);//if higher case, make lower case

	if (counterYN == 'y') { countersOn = true; cout << "\nCountering is on.\n"; }
	else { countersOn = false; cout << "\nCountering is off.\n"; }
	//Players now set up.

	//TODO
	// 1. DONE! Flip a coin to see who attacks first.
	// 2. Take attack/block from each player (high, mid, low).
	// 3. If blocked, attack does no damage, if not blocked, take damage.
	// 4. If attack countered successfully, attacking player takes damage, if not successfully countered, blocking player takes extra damage.
	// 5. Rinse and repeat until someone has health > 1.
	// 6. Game is overm collect your winnings and go home.
	
	cout << "\nA coin will be flipped to determine who starts, do you want heads or tails? Enter H or T: ";

	do {	
	cin >> hOrT;
	} while (hOrT != 'H' && hOrT != 'h' && hOrT != 'T' && hOrT != 't');

	int pChose, coin;

	if (hOrT == 'H' || hOrT == 'h') {	
		cout << "\nYou chose heads.\n"; pChose = 0; 
	} else { 
		cout << "\nYou chose tails.\n"; pChose = 1; 
	}
	
	coin = (rand() % 2);//this will give the remainder of a division by two, so either 0 or 1.
	
	if (coin == 0) {
		cout << "\nHeads!\n";
	} else {
		cout << "\nTails!\n";
	}

	if (coin == pChose) {
		cout << "\nYou got it, you will go first.\n";
		playerTurn = true;
	} else {
		cout <<"\nI got it, I'll go first.\n";
		playerTurn = false;
	}
}
//////////////////////loop////////////////
void Game::loop() {
	
	char pHml;
	char cHml;
	char pCounter;
	bool attempt;
	// game loop, while both players have health, continue playing.
	while (mPlayer.getHealth() > 0 && mComputer.getHealth() > 0)
	{
		attempt = false;
		if (playerTurn) {// the players turn

			//get the players move input
			pHml = getPlayerMove(playerTurn);
			//print the players choice
			printMove(pHml,true,playerTurn);

			//the computers block
			cHml = highMidOrLow();
			printMove( cHml, false, false );
			
			//TODO
			//have a roll to see if the computer attempts a counter
			if (countersOn)
			{
				attempt = randBool();
				cout << "\nI attempt a block.\n";
				outcome(pHml, cHml, playerTurn, attempt); 					
			}
			else {
				//decide outcome and change health values to suit
				outcome(pHml, cHml, playerTurn);
			}

			//change turn to computers
			playerTurn = false;
		} else {// the computers turn

			//take in the players block
			//get the players move input
			pHml = getPlayerMove(playerTurn);
			//print the players choice
			printMove(pHml,true,playerTurn);
			
			//TODO
			//take in whether the player counters
			if (countersOn) {
				cout << "\nDo you want to attempt a counter, for if your block succeeds? (If a counter fails, you will suffer twice the damage.) (Y/N)";
				do { cin >> pCounter; } while ( (pCounter != 'Y') && (pCounter != 'y') && (pCounter != 'N') && (pCounter != 'n'));
				pCounter = makeCharSmall(pCounter);
				if (pCounter == 'y')
					attempt = true;
				else attempt = false;
			}

			//decide the computers attack
			cHml = highMidOrLow();
			printMove( cHml, false, true );

			//decide outcome
			//change health values to suit
			outcome(pHml, cHml, playerTurn, attempt);

			playerTurn = true;
		}
	}

	//end game message
	if (mPlayer.getHealth() < 1) {
		cout << "\nI beat you. Don't underestimate me next time, buddy.\n";
	} else {
		cout <<"\nYou beat me. I should never have underestimated you.\n";
	}
}

void Game::printMove(char highMidLow, bool isPlayer, bool isAttack)
{
	string selfId; 
	if (isPlayer) selfId = "You ";
	else selfId = "I ";
	
	string moveId;
	if (isAttack) moveId = "attack ";
	else moveId = "block ";

	string posId;
	switch(highMidLow) {
		case 'h':
			posId = "high.";
			break;
		case 'm':
			posId = "mid.";
			break;;
		case 'l':
			posId = "low.";
			break;
		default:
			cout << "\nGGGGGGFFFFFFFFFFUUUUUURBLEEEHIGHITIIIIIS.\n";
			posId = "high.";					
	}
	cout << "\n" << selfId << moveId << posId << "\n";
}

char Game::highMidOrLow()
{
	int rand3 = (rand()&3);//gets a random number 0, 1 or 2
	if (rand3 == 0) return 'h';
	else if (rand3 == 1) return 'm';
	else return 'l';
}

bool Game::randBool()
{
	return (rand()%2) == 1; //will return a random 0 or 1 value
}

char Game::getPlayerMove(bool attack)
{
	char movPos;
	string movName;
	if (attack) movName = "attack";
	else movName = "block";
	//take in players attack
	cout << "\nAre you going to " << movName << " high, mid, or low? (H/M/L): ";
	do { cin >> movPos; } while ( (movPos != 'H') && (movPos != 'h') && (movPos != 'M') && (movPos != 'm') && (movPos != 'L') && (movPos != 'l') );
	
	//for debugging purposes
	/*if (movPos < 97) { //if higher case, make lowercase.
		cout << endl << " Variable movPos was : " << movPos << endl;
		movPos+=32;
		cout << endl << " Variable movPos now : " << movPos << endl;
	}*/

	movPos = makeCharSmall(movPos);
	return movPos;
}

void Game::outcome(char pMove, char cMove, bool isPlayerMove, bool attemptCounter)
{
	//decide outcome
	if (pMove == cMove) { 
		cout << "\nAttack was successfully blocked.\n";

		if (attemptCounter)
		{
			cout << "\nCounter attack landed\n";
			//whoever was countered loses health
			if (!isPlayerMove) {	
			mComputer.takeHealth(mPlayer.getHitStrength());
			} else {
				mPlayer.takeHealth(mComputer.getHitStrength());
			}
		}
	} else { 
		cout << "\nAttack was not blocked, damage was sustained.\n";

		if (isPlayerMove) {	
			mComputer.takeHealth(mPlayer.getHitStrength());
		} else {
			mPlayer.takeHealth(mComputer.getHitStrength());
		}

		if (attemptCounter)
		{
			cout << "\nCounter fails too, damage was doubled.\n";
			//quick and dirty doubling of damage
			if (isPlayerMove) {	
			mComputer.takeHealth(mPlayer.getHitStrength());
			} else {
				mPlayer.takeHealth(mComputer.getHitStrength());
			}
		}
	}
	cout << "\nHow we stand; You have " << mPlayer.getHealth() << " health. I have " << mComputer.getHealth() << " health.\n";
}

char Game::makeCharSmall(char character)
{
	if (character < 97) character +=32;
	return character;
}
