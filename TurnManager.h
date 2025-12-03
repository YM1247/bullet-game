#ifndef TURNMANAGE_H
#define TURNMANAGE_H

#include "Player.h"

class TurnManager {
    private:
        Player *current;
        Player *opponent;
        // 追蹤擁有額外射擊機會的玩家
        Player *extraShotPlayer = nullptr; 

    public:
        void initTurn(Player& first, Player& second);
        void swap();      // 換人
        void grantExtraShot(Player& p);
        bool hasExtraShot(Player& p);
    
        // 新增：方便外部存取的 getter
        Player* getCurrentPlayer() { return current; }
        Player* getOpponentPlayer() { return opponent; }
};

#endif
