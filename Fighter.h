#ifndef FIGHTER_H
#define FIGHTER_H

class Fighter {
public:	
	Fighter(int health, int hitStrength);
	~Fighter();
	int getHealth;
	void takeHealth( int damage );
	int getHitStrength();
private:
	int mHealth;
	int mHitStrength;
};

#endif