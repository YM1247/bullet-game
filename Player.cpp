#include "Player.h"
#include "BulletDeck.h"
#include "TurnManager.h"

Player::Player() {
	character = new Character;
}

Player::~Player() {
	delete[] character;
}

char Player::chooseDirection() {

	scanf("%s", &position);

	if (position == 'A') {
		return 'L';
	}

	else if (position == 'D') {
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
		character->useSkill(BulletDeck gun, Player &myself, Player &opponent);
	}
}

void Player::skillInvalid(){

}
void Player::getExtraBlood(){
	hp += 1;
}