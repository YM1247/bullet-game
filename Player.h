#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    private:
    int hp;
    int skillPoint;
    Character *character;
    bool hasExtraShot;

    public:
    char chooseDirection(); // L/R
    void takeDamage(int dmg);
    bool isDead();
    void applySkillTrigger();
    
    void skillInvalid(); // for OldJuang's skill
};

#endif