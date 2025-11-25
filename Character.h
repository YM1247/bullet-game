#ifndef CHARACTER_H
#define CHARACTER_H

#include "BulletDeck.h"
#include "Player.h"

class Character {
    protected:
    int skillLimit;
    int currentSkillValue;

    public:
    Character();
    virtual ~Character() {};
    virtual void useSkill() {};
};

// other characters may be like:
class Elliot : public Character {
    public:
    Elliot() : Character() {};
    ~Elliot() {};
    void useSkill(BulletDeck gun); 
};
class BigJay : public Character {
    public:
    BigJay() : Character() {};
    ~BigJay() {};
    void useSkill();     
};
class OldJuang : public Character {
    public:
    OldJuang() : Character() {};
    ~OldJuang() {};
    void useSkill(Player opponent);
};
class YaJu : public Character {};
class MingJen : public Character {};

#endif