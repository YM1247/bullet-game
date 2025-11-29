#include "Player.h"
#include "BulletDeck.h"

Player::Player() {}

Player::~Player() {
	delete[] character;
}

void Player::chooseCharacter(int index) {
	if (index == 0)
		character = new Elliot;

	else if (index == 1)
		character = new BigJay;

	else if (index == 2)
		character = new OldJuang;

	else if (index == 3)
		character = new YaJu;

	else if (index == 4)
		character = new Ming;

	else {
		printf("請輸入正確的角色編號\n");
		chooseCharacter(index); //直到輸入正確的編號為止
	}
}

char Player::chooseDirection() {
	scanf("%s", &position);

	if (position == 'A' || position == 'a') {
		return 'L';
	}

	else if (position == 'D' || position == 'd') {
		return 'R';
	}

	else{
		printf("請輸入 A 或 D\n");
	}
}

void Player::takeDamage(int dmg) {
	hp -= dmg;

	if (hp <= 0){
		hp = 0;
	}

	printf("受到了%d點傷害\n", dmg);
}

bool Player::isDead() {
	return (hp == 0) ? true : false; // if hp = 0, the player's dead
}

bool Player::applySkillTrigger(BulletDeck gun, Player &opponent) {
	if (skillPoint >= character->skillLimit) {
		character->useSkill(gun, *this, opponent);

		skillPoint -= character->skillLimit;

		printf("發動技能，使用技能點數%d點，目前剩下%d點\n", character->skillLimit, skillPoint);
		return true;
	}

	else {
		printf("技能點數不足，無法發動技能\n");
		return false;
	}
}

void Player::skillInvalid() {}
void Player::getExtraBlood() {
	hp += 1;
}

int Player::calDmg(BulletDeck gun, Player &opponent) {
	if (gun.fire() == false)
		return 0;

	else if (gun.fire() == true && applySkillTrigger(gun, opponent) && character->ID == 3)
		return 2;

	else if (gun.fire() == true)
		return 1;
}