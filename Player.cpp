#include "Player.h"
#include <cstdio>
#include <stdexcept>
using namespace std;

Player::Player() {
	hp = 10;
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
		try {
			printf("按「9」來檢視角色資訊");
            if (scanf("%d", &index) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {   // 清掉我們不接受的輸入，如字母
                }
                throw logic_error("輸入格式錯誤：請輸入 0–4 或 9\n");
            }
			if (index < 0 || (index > 4 && index != 9)) {
				throw logic_error("操作失敗：請輸入正確數字\n");
			}
	
			switch (index) {
			case 0:
				character = new Elliot;
				printf("你選擇了Elliot，又帥又聰明的經濟學家！\n\n");
				return;
	
			case 1:
				character = new BigJay;
				printf("你選擇了大傑，！\n\n");
				return;
	
			case 2:
				character = new OldJuang;
				printf("你選擇了老莊，騎腳踏車去北海道的勇者！\n\n");
				return;
	
			case 3:
				character = new YaJu;
				printf("你選擇了雅茄，！\n\n");
				return;
	
			case 4:
				character = new Ming;
				printf("你選擇了阿仁，帥帥小農場的少東！\n\n");
				return;
			case 9:
				printf("---------  角色資訊  ---------\n");
				printf("0: Elliot，又帥又聰明的經濟學家，知道目前子彈是實？是虛？\n");
				printf("1: 大傑，迷幻點心之王，迫使吃下點心的對手將槍指向自己\n");
				printf("2: 老莊，騎腳踏車去北海道的勇者，躲避對手技能\n");
				printf("3: 雅茄，乒乓球女王，特化子彈讓對方造成雙倍傷害\n");
				printf("4: 阿仁，帥帥小農場的少東，能喝自家產新鮮牛奶補血\n");
				printf("-----------------------------\n");
			default:
				printf("請輸入正確的角色編號\n");
			}
		}
		catch (const logic_error& e) {
            printf("%s", e.what());
		}
	}
}

char Player::chooseDirection() {
	if (isDirectionFixed == true) {
		printf("你的方向被對方鎖定了");
		isDirectionFixed = false;
		return 'L';
	}

	while (true) {
		try {
			if (scanf(" %c", &direction) != 1) {
				int ch;
				while ((ch = getchar()) != '\n' && ch != EOF) {}  // 清掉後面字母
				throw logic_error("輸入格式錯誤\n");
			}
			int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}  // 清掉後面字母

            if (direction != 'A' && direction != 'a' &&
                direction != 'D' && direction != 'd') {
                throw logic_error("操作失敗：請輸入 A/D 或 a/d\n");
            }

			if (direction == 'A' || direction == 'a')
				return 'L';
	
			else if (direction == 'D' || direction == 'd')
				return 'R';
	
			else
				printf("請輸入正確方向\n");
		}
		catch (const logic_error& e) {
			printf("%s", e.what());
		}
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

int Player::getHP() {
	return this->hp;
}

int Player::getSkill() {return skillPoint;}

int Player::getSkillLim() {return character->skillLimit;}