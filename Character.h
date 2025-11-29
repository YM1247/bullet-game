#ifndef CHARACTER_H
#define CHARACTER_H

#include "BulletDeck.h"
#include "Player.h"

class Character {
	friend class Player;

protected:
	int ID;
	int skillLimit;

public:
	Character();
	virtual ~Character() {};
	virtual void useSkill(BulletDeck gun, Player &myself, Player &opponent) {};
};

// other characters may be like:
class Elliot : public Character {
public:
	Elliot() : Character() {};
	~Elliot() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class BigJay : public Character {
public:
	BigJay() : Character() {};
	~BigJay() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class OldJuang : public Character {
public:
	OldJuang() : Character() {};
	~OldJuang() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class YaJu : public Character {
public:
	YaJu() : Character() {};
	~YaJu() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class Ming : public Character {
public:
	Ming() : Character() {};
	~Ming() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

#endif