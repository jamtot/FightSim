#ifndef FIGHTER_H
#define FIGHTER_H

class Fighter {
public:	
	//Fighter(int health, int hitStrength);//added init
	Fighter();
	~Fighter();
	void init(int health, int hitStrength);
	int getHealth();
	void takeHealth( int damage );
	int getHitStrength();
private:
	int mHealth;
	int mHitStrength;
};

#endif
