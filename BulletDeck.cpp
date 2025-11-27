#include "BulletDeck.h"
#include "Player.h"

BulletDeck::BulletDeck() {
	index = 0;
}
BulletDeck::~BulletDeck() {}

void BulletDeck::generate(int realCount, int blankCount) {
	int slotLength = realCount + blankCount;
	srand(time(0));
	int rn = 0;

	for (int slot = 0; slot < slotLength; slot++) {
		bullets.push_back(rand() % 2);

		if (bullets[slot] == 1) {
			realCount--;
		} else {
			blankCount--;
		}

		if (realCount == 0) {
			for (int s = 0; s < blankCount; s++)
				bullets.push_back(0);
			break;
		}

		else if (blankCount == 0) {
			for (int s = 0; s < blankCount; s++)
				bullets.push_back(1);
			break;
		}
	}
}

bool BulletDeck::fire() {

	if (bullets[index] != 0) {
		index++;
		return true; // Fire real bullet
	}

	else {
		index++;
		return false; // No fire bullet
	}
}

bool BulletDeck::hasNext() { // Identify whether this is the final bullet slot
	if (index >= realCount + blankCount - 1) { // If the index is the final one
		return false;
	}

	else
		return true;
}

void BulletDeck::fixedDirection(Player *opponent) { // Force the opponent take damage
	opponent->takeDamage(fire());
}