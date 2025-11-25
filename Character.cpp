#include "Player.h"
#include <iostream>

Character::Character() {
    this->skillLimit = -1;    
    this->currentSkillValue = -1;
}
Character::~Character() {}

// Elliot: the smart & handsome economist
// Skill: Sees the status of the current bullet (real or blank)
Elliot::Elliot() {
    skillLimit = 3;
    currentSkillValue = 0;
}
void Elliot::useSkill(BulletDeck gun) {
    // check: if current < limit -> cannot trigger skill
    if(currentSkillValue < skillLimit) return;
    // bullet is real: 
    if(gun.fire())
        std::cout << "real" << "\n";
    // else, bullet is blank:
    else
        std::cout << "blank" << "\n";
    // reset accumulated skill value    
    currentSkillValue = 0;
}
// BigJay: 
// Skill:
BigJay::BigJay() {
    skillLimit = 3;
    currentSkillValue = 0;
}
void BigJay::useSkill() {
    if(currentSkillValue < skillLimit) return;
    // use skill
    currentSkillValue = 0;
}
// OldJuang: rides his bike to Hokkaido
// Skill: Dodges opponent's skill
OldJuang::OldJuang() {
    skillLimit = 3;
    currentSkillValue = 0;
}
void OldJuang::useSkill(Player opponent) {
    // check: if current < limit -> cannot trigger skill
    if(currentSkillValue < skillLimit) return;
    // use skill
    opponent.skillInvalid();
    currentSkillValue = 0;
}