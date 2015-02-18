#include "Fighter.h"

Fighter::Fighter(int health, int hitStrength) : mHealth(health), mHitStrength(hitStrength)
{}

Fighter::~Fighter()
{}

int Fighter::getHealth() {
	return mHealth; 
}
void Fighter::takeHealth( int damage ) {
	mHealth -= damage; 
}

int Fighter::getHitStrength() {
	return mHitStrength;
}
