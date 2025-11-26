#include "Player.h" // necessary ?
#include <iostream>

Character::Character() {
    this->skillLimit = -1;    
}
Character::~Character() {}

// Elliot: the smart & handsome economist
// Skill: Sees the status of the current bullet (real or blank)
Elliot::Elliot() {
    skillLimit = 3;
}
void Elliot::useSkill(BulletDeck gun, Player& myself, Player& opponent) {
    // bullet is real: 
    if(gun.fire())
        std::cout << "real" << "\n";
    // else, bullet is blank:
    else
        std::cout << "blank" << "\n";   
}
// BigJay: Hand out candies that mess up your mind
// Skill: Forces opponent to shoot him/herself
BigJay::BigJay() {
    skillLimit = 3;
}
void BigJay::useSkill(BulletDeck gun, Player& myself, Player& opponent) {
    gun.fixedDirection();
}
// OldJuang: rides his bike to Hokkaido
// Skill: Dodges opponent's skill
OldJuang::OldJuang() {
    skillLimit = 3;
}
void OldJuang::useSkill(BulletDeck gun, Player& myself, Player& opponent) {
    // use skill
    opponent.skillInvalid();
}
// YaJu: throws ping-pong balls
// Skill: Double damage to opponent
YaJu::YaJu() {
    skillLimit = 3;
}
void YaJu::useSkill(BulletDeck gun, Player& myself, Player& opponent) {
    // use skill
    if(gun.fire())
        opponent.takeDamage(2);    
}
// Ming: owner of handsome handsome little farm
// Skill: get extra blood
Ming::Ming() {
    skillLimit = 3;
}
void Ming::useSkill(BulletDeck gun, Player& myself, Player& opponent) {
    // use skill
    myself.getExtraBlood();
}