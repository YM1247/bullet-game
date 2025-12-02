#include "Game.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

void Game::start() {
    initPlayers();
    chooseFirst();
    while(true) {
        
    }
}

void Game::initPlayers() {
    player1.chooseCharacter();
    player2.chooseCharacter();
}

void Game::chooseFirst() {
    srand((unsigned)time(nullptr));  // 用目前時間為種子
    if(rand() % 2) {
        cout << "player1 先手" << endl;
        turn.initTurn(player1, player2);
        return;
    } else { 
        cout << "player2 先手" << endl;
        turn.initTurn(player2, player1);
        return;
    }
}