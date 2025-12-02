#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "TurnManager.h"

class Game {
    private:
    Player player1;
    Player player2;
    TurnManager turn;

    public:
    void start();
    void initPlayers();
    void chooseFirst();
    void startRound();
    void endGame();
};

#endif