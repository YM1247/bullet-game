#include "Character.h"

class Player {
    private:
    int hp;
    Character *character;
    bool hasExtraShot;

    public:
    char chooseDirection(); // L/R
    void takeDamage(int dmg);
    bool isDead();
    void applySkillTrigger();
};