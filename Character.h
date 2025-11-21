#ifndef CHARACTER_H
#define CHARACTER_H

#include "BulletDeck.h"

class Character {
    protected:
    int skillCD;

    public:
    virtual ~Character();
    virtual void useSkill();
};

// other characters may be like:
class Elliot : public Character {};
class BigJay : public Character {};
class YaJu : public Character {};
class OldJuang : public Character {};
class MingJen : public Character {};

#endif