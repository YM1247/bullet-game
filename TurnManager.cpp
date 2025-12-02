#include "TurnManager.h"

void TurnManager::initTurn(Player& first, Player& second) {
    // 設定當前玩家和對手
    current = &first;
    opponent = &second;
    // 重置所有特殊回合狀態
    extraShotPlayer = nullptr; 

    // 初始化時，順便確保兩位玩家的狀態是乾淨的
      current->setSkillInvalid(false);
      current->setDirectionFixed(false);
      current->doubleDamage(false);
      
      opponent->setSkillInvalid(false);
      opponent->setDirectionFixed(false);
      opponent->doubleDamage(false);
}

void TurnManager::swap() {
    // 使用暫存變數進行指標交換
    Player *temp = current;
    current = opponent;
    opponent = temp;

    if (current != nullptr) {
            // 重置技能使用狀態 (假定 setSkillInvalid(false) 代表技能可用)
            current->setSkillInvalid(false);
            
            // 重置方向固定狀態
            current->setDirectionFixed(false);
            
            // 重置傷害加倍狀態
            current->doubleDamage(false);
        }
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

/* #include "TurnManager.h"

void swap() {}

void grantExtraShot(Player &p) {}

bool hasExtraShot(Player &p) {} */
// 換人的時候記得要把player裡面好幾個variable都初始化喔 我都有寫好setter可以直接用
