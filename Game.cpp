#include "Game.h"

void Game::start() {
    initPlayers();
}

void Game::initPlayers() {
    player1.chooseCharacter();
    player2.chooseCharacter();
}