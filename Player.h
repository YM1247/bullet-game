#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <cstring>

class Player {
    private:
    int hp;
    int skillPoint;
    Character *character;
    bool hasExtraShot;

    char position; // L/R

    public:
    Player();
    ~Player();

    char chooseDirection(); // L/R
    void chooseCharacter(int index);
    void takeDamage(int dmg); // hp-=dmg
    bool isDead(); // if hp = 0
    bool applySkillTrigger(BulletDeck gun, Player &opponent); // if the skill point is enough to trigger the skill, then trigger.
    int calDmg(BulletDeck gun, Player &opponent);
    void skillInvalid(); // for OldJuang's skill ?
    void getExtraBlood(); // for Ming's skill ?
};

#endif