#include "Player.h"

char Player::chooseDirection() {}

void Player::takeDamage(int dmg) {}

bool Player::isDead() {
	return (hp == 0) ? true : false; // if hp = 0, the player's dead
}

void Player::applySkillTrigger() {}