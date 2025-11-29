#include "Player.h"
#include "BulletDeck.h"

Player::Player() {
	hp = 3;
	skillPoint = 0;
	character = nullptr;
	isDamageDoubled = false;
	canUseSkill = true;
	direction = {};
	isDirectionFixed = false;
}

Player::~Player() {
	delete character;
	character = nullptr;
}

void Player::chooseCharacter() {
	int index = 0;

	while (true) {
		scanf("%d", &index);

		switch (index) {
		case 0:
			character = new Elliot;
			return;

		case 1:
			character = new BigJay;
			return;

		case 2:
			character = new OldJuang;
			return;

		case 3:
			character = new YaJu;
			return;

		case 4:
			character = new Ming;
			return;

		default:
			printf("請輸入正確的角色編號\n");
		}
	}
}

char Player::chooseDirection() {
	if (isDirectionFixed == true)
		return 'L';

	while (true) {
		scanf(" %c", &direction);

		if (direction == 'A' || direction == 'a')
			return 'L';

		else if (direction == 'D' || direction == 'd')
			return 'R';

		else
			printf("請輸入 A 或 D\n");
	}
}

void Player::takeDamage(int dmg) {
	hp -= dmg;

	if (hp <= 0) {
		hp = 0;
	}

	printf("受到了%d點傷害\n", dmg);
}

bool Player::isDead() {
	return (hp == 0) ? true : false; // if hp = 0, the player's dead
}

bool Player::applySkillTrigger(BulletDeck &curBullet, Player &opponent,
							   int skillLimit) {

	if (canUseSkill == false) {
		printf("你的技能無法發動\n");
		return false;
	}

	if (skillPoint >= skillLimit) { // 如果技能點數足夠

		character->useSkill(curBullet, *this, opponent); // 發動技能

		skillPoint -= skillLimit; // 扣點數

		printf("發動技能，使用技能點數%d點，目前剩下%d點\n", skillLimit,
			   skillPoint);
		return true;
	}

	else {
		printf("技能點數不足，無法發動技能\n");
		return false;
	}
}

void Player::setSkillInvalid(bool index) {
	canUseSkill = index;
}

void Player::getExtraBlood() {
	hp += 1;
}

int Player::calDmg(BulletDeck curBullet) {
	if (curBullet.isRealBullet() == false)
		return 0;

	else if (curBullet.isRealBullet() && isDamageDoubled == true)
		return 2;

	else
		return 1;
}

void Player::setDirectionFixed(bool index) {
	isDirectionFixed = index;
}

void Player::doubleDamage(bool index) {
	isDamageDoubled = index;
}