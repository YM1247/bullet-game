#include "Character.h"
#include <iostream>

Character::Character() {
    this->skillLimit = -1;    
    this->currentSkillValue = -1;
}
Character::~Character() {}

// Elliot: the smart & handsome economist
// Skill: See the status of the current bullet (real or blank)
Elliot::Elliot() {
    skillLimit = 3;
    currentSkillValue = 0;
}
void Elliot::useSkill() {
    if(currentSkillValue < skillLimit) return;
    // if bullet is real:
    std::cout << "real" << "\n";
    // if bullet is blank:
    std::cout << "blank" << "\n";
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