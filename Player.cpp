#include "Player.h"
#include "BulletDeck.h"
#include "TurnManager.h"

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
}

char Player::chooseDirection() {
	scanf("%s", &position);

	if (position == 'A' || position == 'a') {
		return 'L';
	}

	else if (position == 'D' || position == 'd') {
		return 'R';
	}
}

void Player::takeDamage(int dmg) {
	hp -= dmg;
}

bool Player::isDead() {
	return (hp == 0) ? true : false; // if hp = 0, the player's dead
}

bool Player::applySkillTrigger() {
	if (skillPoint >= 3) {
	}
}

void Player::skillInvalid() {}
void Player::getExtraBlood() {
	hp += 1;
}

int Player::calDmg(BulletDeck gun) {
	if (gun.fire() == false)
		return 0;

	else if (gun.fire() == true)
		return 1;

	else if (gun.fire() == true)
}