#ifndef CHARACTER_H
#define CHARACTER_H

#include "BulletDeck.h"

class Character {
    protected:
    int skillLimit;
    int currentSkillValue;

    public:
    Character();
    virtual ~Character() {};
    virtual void useSkill();
};

// other characters may be like:
class Elliot : public Character {
    public:
    Elliot() : Character() {};
    ~Elliot() {};
    void useSkill(); 
};
class BigJay : public Character {
    public:
    BigJay() : Character() {};
    ~BigJay() {};
    void useSkill();     
};
class YaJu : public Character {};
class OldJuang : public Character {};
class MingJen : public Character {};

#endif