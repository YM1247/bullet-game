#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    private:
    int hp;
    int skillPoint;
    Character *character;

    bool isDamageDoubled;
    bool canUseSkill;
    bool isDirectionFixed;

    char direction; // L/R

    public:
    Player();
    ~Player();

    char chooseDirection(); // 輸入a或d, 回傳L或R
    void chooseCharacter(); //依照角色編號創建charater
    void takeDamage(int dmg); // hp -= dmg
    bool isDead(); // if hp = 0 return true
    bool applySkillTrigger(BulletDeck &curBullet, Player &opponent, int skillLimit); // if the skill point is enough to trigger the skill, then trigger.
    int calDmg(BulletDeck curBullet); // return how much damage will the player take

    void setSkillInvalid(bool index); // for OldJuang's skill, set cnaUseSkill
    void getExtraBlood(); // for Ming's skill, hp += 1
    void setDirectionFixed(bool index); // for BIgJay's skill, set isDirectionFixed
    void doubleDamage(bool index); // for YaJus's skill, set hasExtraShot
};

#endif