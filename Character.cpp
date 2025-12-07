#include "Player.h"
#include <iostream>
#include <cstring>

Character::Character() {
	this->ID = -1;
	this->skillLimit = -1;
}

// 0 : Elliot: the smart & handsome economist
// Skill: Sees the status of the current bullet (real or blank)
Elliot::Elliot() : Character() {
	ID = 0;
	skillLimit = 2;
}

void Elliot::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// bullet is real:
	std::cout << "發動技能【逆向歸納法】！" << "\n"; 
	if (gun.isRealBullet() == true)
		std::cout << "目前子彈是【實彈】！" << "\n";
	// else, bullet is blank:
	else
		std::cout << "目前子彈是【虛彈】！" << "\n";
}

// 1 : BigJay: Hand out candies that mess up your mind
// Skill: Forces opponent to shoot him/herself
BigJay::BigJay() : Character() {
    ID = 1;
	skillLimit = 2;
}

void BigJay::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	opponent.setDirectionFixed(true);
	std::cout << "發動技能【強制最佳化】！" << "\n";
}
// 2 : OldJuang: rides his bike to Hokkaido
// Skill: Dodges opponent's skill
OldJuang::OldJuang() : Character() {
    ID = 2;
	skillLimit = 3;
}

void OldJuang::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	myself.setCanDodge(true);
	std::cout << "發動技能【校外教學】！" << "\n";
}
// 3 : YaJu: throws ping-pong balls
// Skill: Double damage to opponent
YaJu::YaJu() : Character() {
    ID = 3;
	skillLimit = 3;
}

void YaJu::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	opponent.doubleDamage(true);
	std::cout << "發動技能【加分作業】" << "\n";
}

// 4 : Ming: owner of handsome handsome little farm
// Skill: get extra blood
Ming::Ming() : Character() {
    ID = 4;
	skillLimit = 3;
}

void Ming::useSkill(BulletDeck gun, Player &myself, Player &opponent) {
	// use skill
	myself.getExtraBlood();
	std::cout << "發動技能【】！" << "\n";
	std::cout << "喝下自家產新鮮牛奶，加一滴血！" << "\n";
}
