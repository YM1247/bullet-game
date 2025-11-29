#include "Player.h" // necessary ?
#include <iostream>

Character::Character() {
    this->ID = -1;
	this->skillLimit = -1;
}
Character::~Character() {}

// 0 : Elliot: the smart & handsome economist
// Skill: Sees the status of the current bullet (real or blank)
Elliot::Elliot() {
    ID = 0;
	skillLimit = 3;
}

void Elliot::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// bullet is real:
	if (gun.isRealBullet() == true)
		std::cout << "real" << "\n";
	// else, bullet is blank:
	else
		std::cout << "blank" << "\n";
}

// 1 : BigJay: Hand out candies that mess up your mind
// Skill: Forces opponent to shoot him/herself
BigJay::BigJay() {
    ID = 1;
	skillLimit = 3;
}

void BigJay::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	opponent.setDirectionFixed(true);
}
// 2 : OldJuang: rides his bike to Hokkaido
// Skill: Dodges opponent's skill
OldJuang::OldJuang() {
    ID = 2;
	skillLimit = 3;
}

void OldJuang::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	opponent.setSkillInvalid(false);
}
// 3 : YaJu: throws ping-pong balls
// Skill: Double damage to opponent
YaJu::YaJu() {
    ID = 3;
	skillLimit = 3;
}

void YaJu::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	if (gun.isRealBullet())
		opponent.doubleDamage(true);
}

// 4 : Ming: owner of handsome handsome little farm
// Skill: get extra blood
Ming::Ming() {
    ID = 4;
	skillLimit = 3;
}

void Ming::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	myself.getExtraBlood();
}