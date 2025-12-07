#ifndef PLAYER_H
#define PLAYER_H

#include "BulletDeck.h"
#include <string>

class Character;

class Player {
    private:
    int hp;
    int skillPoint;
    Character *character;

    bool isDamageDoubled;
    bool canUseSkill;
    bool isDirectionFixed;
    bool canDodge;

    char direction; // L/R

    public:
    Player();
    ~Player();

    char chooseDirection(); // 輸入a或d, 回傳L或R
    void chooseCharacter(); //依照角色編號創建charater
    void takeDamage(int dmg); // hp -= dmg
    bool isDead(); // if hp = 0 return true
    bool applySkillTrigger(BulletDeck &curBullet, Player &opponent); // if the skill point is enough to trigger the skill, then trigger.
    int calDmg(BulletDeck &curBullet); // return how much damage will the player take
    void gainSkillPt();

    void setSkillInvalid(bool status); // for OldJuang's skill, set cnaUseSkill
    void getExtraBlood(); // for Ming's skill, hp += 1
    void setDirectionFixed(bool status); // for BIgJay's skill, set isDirectionFixed
    void doubleDamage(bool status); // for YaJus's skill, set hasExtraShot
    bool getDoubleDamage();
    int getHP();
    int getSkill();
    int getSkillLim();
    bool setCanDodge(bool status);
    bool shouldDodge();
    string getName();
};

// Character.h Section

class Character {
friend class Player;

protected:
	int ID;
	int skillLimit;
    string name;

public:
	Character();
	virtual ~Character() {};
	virtual void useSkill(BulletDeck gun, Player &myself, Player &opponent) {};
    const char* getName() const;
};

// other characters may be like:
class Elliot : public Character {
public:
	Elliot();
	~Elliot() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class BigJay : public Character {
public:
	BigJay();
	~BigJay() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class OldJuang : public Character {
public:
	OldJuang();
	~OldJuang() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class YaJu : public Character {
public:
	YaJu();
	~YaJu() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

class Ming : public Character {
public:
	Ming();
	~Ming() {};
	void useSkill(BulletDeck gun, Player &myself, Player &opponent);
};

#endif