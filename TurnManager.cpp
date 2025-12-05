#include "TurnManager.h"

void TurnManager::initTurn(Player& first, Player& second) {
    // 設定當前玩家和對手
    current = &first;
    opponent = &second;

    // 一開始沒有額外射擊的玩家
    extraShotPlayer = nullptr; 
}

void TurnManager::swap() {
    // 使用暫存變數進行指標交換
    Player *temp = current;
    current = opponent;
    opponent = temp;
}

void TurnManager::grantExtraShot(Player& p) {
    // 記錄擁有額外射擊機會的玩家
    extraShotPlayer = &p;
}

bool TurnManager::hasExtraShot(Player& p) {
    if (extraShotPlayer == &p) {
        // 成功，且消耗掉這個機會，避免重複使用
        extraShotPlayer = nullptr;
        return true;
    }
    return false;
}
