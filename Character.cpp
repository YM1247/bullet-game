#include "Player.h"
#include <iostream>
#include <cstring>

Character::Character() {
    std::strcpy(this->name, "");
	this->ID = -1;
	this->skillLimit = -1;
}

const char* Character::getName() const{
	return this->name;
}
// 0 : Elliot: the smart & handsome economist
// Skill: Sees the status of the current bullet (real or blank)
Elliot::Elliot() : Character() {
    std::strcpy(this->name, "Elliot");
	ID = 0;
	skillLimit = 3;
}

void Elliot::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// bullet is real:
	if (gun.isRealBullet() == true)
		std::cout << "目前子彈是「實彈」！" << "\n";
	// else, bullet is blank:
	else
		std::cout << "目前子彈是「虛彈」！" << "\n";
}

// 1 : BigJay: Hand out candies that mess up your mind
// Skill: Forces opponent to shoot him/herself
BigJay::BigJay() : Character() {
	std::strcpy(this->name, "BigJay");
    ID = 1;
	skillLimit = 3;
}

void BigJay::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	opponent.setDirectionFixed(true);
	std::cout << "你鎖定了對手的方向！" << "\n";
}
// 2 : OldJuang: rides his bike to Hokkaido
// Skill: Dodges opponent's skill
OldJuang::OldJuang() : Character() {
	std::strcpy(this->name, "OldJuang");
    ID = 2;
	skillLimit = 3;
}

void OldJuang::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	opponent.setSkillInvalid(false);
	std::cout << "對手技能無效化了！" << "\n";
}
// 3 : YaJu: throws ping-pong balls
// Skill: Double damage to opponent
YaJu::YaJu() : Character() {
	std::strcpy(this->name, "YaJu");
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
Ming::Ming() : Character() {
	std::strcpy(this->name, "Ming");
    ID = 4;
	skillLimit = 3;
}

void Ming::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	myself.getExtraBlood();
	std::cout << "喝下自家產新鮮牛奶，加一滴血！" << "\n";
}
