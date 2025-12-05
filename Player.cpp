#include "Player.h"
#include <cstdio>

Player::Player() {
	hp = 3;
	skillPoint = 0;
	character = nullptr;
	isDamageDoubled = false;
	canUseSkill = true;
	direction = 'N';
	isDirectionFixed = false;
}

Player::~Player() {
	delete character;
	character = nullptr;
}

void Player::chooseCharacter() {
	int index = 0;

	while (true) {
		printf("按「9」來檢視角色資訊");
		scanf("%d", &index);

		switch (index) {
		case 0:
			character = new Elliot;
			printf("你選擇了Elliot，又帥又聰明的經濟學家！\n");
			return;

		case 1:
			character = new BigJay;
			printf("你選擇了大傑，！\n");
			return;

		case 2:
			character = new OldJuang;
			printf("你選擇了老莊，騎腳踏車去北海道的勇者！\n");
			return;

		case 3:
			character = new YaJu;
			printf("你選擇了，！\n");
			return;

		case 4:
			character = new Ming;
			printf("你選擇了，帥帥小農場的少東！\n");
			return;
		case 9:
			printf("---------  角色資訊  ---------\n");
			printf("0: Elliot，又帥又聰明的經濟學家\n");
			printf("1: 大傑，點心之王\n");
			printf("2: 老莊，騎腳踏車去北海道的勇者\n");
			printf("3: 雅茄，乒乓球女王\n");
			printf("4: 阿仁，帥帥小農場的少東\n");
		default:
			printf("請輸入正確的角色編號\n");
		}
	}
}

char Player::chooseDirection() {
	if (isDirectionFixed == true) {
		printf("你的方向被對方鎖定了");
		return 'L';
	}

	while (true) {
		scanf(" %c", &direction);

		if (direction == 'A' || direction == 'a')
			return 'L';

		else if (direction == 'D' || direction == 'd')
			return 'R';

		else
			printf("請輸入正確方向\n");
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

bool Player::applySkillTrigger(BulletDeck &curBullet, Player &opponent) {

	if (canUseSkill == false) {
		printf("你的技能無法發動\n");
		return false;
	}

	if (skillPoint >= character->skillLimit) { // 如果技能點數足夠

		character->useSkill(curBullet, *this, opponent); // 發動技能

		skillPoint -= character->skillLimit; // 扣點數

		printf("發動技能，使用技能點數%d點，目前剩下%d點\n",
			   character->skillLimit, skillPoint);
		return true;
	}

	else {
		printf("技能點數不足，無法發動技能\n");
		return false;
	}
}

void Player::setSkillInvalid(bool status) {
	canUseSkill = status;
}

void Player::getExtraBlood() {
	hp += 1;
}

int Player::calDmg(BulletDeck &curBullet) {
	if (curBullet.isRealBullet() == false)
		return 0;

	else if (curBullet.isRealBullet() && isDamageDoubled == true)
		return 2;

	else
		return 1;
}

void Player::setDirectionFixed(bool status) {
	isDirectionFixed = status;
}

void Player::doubleDamage(bool status) {
	isDamageDoubled = status;
}

void Player::gainSkillPt() {
	skillPoint++;
}

bool Player::getDoubleDamage() {
	return isDamageDoubled;
}
