#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    private:
    int hp;
    int skillPoint;
    Character *character;
    bool hasExtraShot;

    char positition; // L/R

    public:
    char chooseDirection(); // L/R
    void takeDamage(int dmg);
    bool isDead();
    void applySkillTrigger();
    
    void skillInvalid(); // for OldJuang's skill ?
    void getExtraBlood(); // for Ming's skill ?
};

#endif