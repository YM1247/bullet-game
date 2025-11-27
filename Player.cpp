#include "Player.h"
#include "BulletDeck.h"
#include "TurnManager.h"

Player::Player() {}

Player::~Player() {
	delete[] character;
}

void Player::chooseCharacter(int index) {
	character = new Elliot;
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

void Player::applySkillTrigger() {
	if (skillPoint >= 3) {
		character->useSkill();
	}
}

void Player::skillInvalid() {}
void Player::getExtraBlood() {
	hp += 1;
}