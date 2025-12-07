#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// --- 遊戲設定 ---
static int REAL_AMMO = 3;  // 實彈數
static int BLANK_AMMO = 2; // 空彈數
const int totalHP = 10;

void Game::start() {
    initPlayers();
    chooseFirst();

    // 初始填彈
    cout << "=== 遊戲開始 (" << REAL_AMMO << "實 " << BLANK_AMMO << "空) ===" << endl;
    gun.generate(REAL_AMMO, BLANK_AMMO);

    while(true) {
        // 1. 判斷勝負
        if (player1.isDead() || player2.isDead()) {
            endGame();
            break;
        }

        // 2. 補充彈藥
        startRound();

        // 3. 獲取當前資訊
        Player* current = turn.getCurrentPlayer();
        Player* opponent = turn.getOpponentPlayer();

        cout << "\n--------------------------------\n";
        cout << (current == &player1 ? "Player 1" : "Player 2") << " 的回合\n";
        // 顯示HP
        cout << "HP： " << current->getHP() << " / " << totalHP << "\n";
        cout << "Skill: " << current->getSkill()  << " / " << current->getSkillLim() << "\n";
        // 4. 技能階段
        current->applySkillTrigger(gun, *opponent);

        // 5. 選擇目標
        cout << "開槍方向 (A:自己 / D:對方): ";
        char dir = current->chooseDirection();
        
        // 6. 開槍
        bool isReal = gun.fire();
        
        // 7. 結算
        if (dir == 'L') { // 射自己
            if (isReal) {
                cout << "【實彈】射中自己！" << endl;
                current->takeDamage(1);
                turn.swap(); // 自爆換人
            } else {
                cout << "【空彈】幸運！額外回合 & 技能點+1" << endl;
                current->gainSkillPt();
                // 繼續回合
            }
        } 
        else { // 射對方
            if (isReal) {
                cout << "【實彈】命中對手！" << endl;
                if(opponent->getDoubleDamage()) { // 對方該被雙倍傷害
                    opponent->takeDamage(2);              
                    opponent->doubleDamage(false); // 重設狀態
                }
                else { // 對方該被正常傷害
                    opponent->takeDamage(1);
                } 
                turn.swap(); // 擊中換人
            } else {
                cout << "【空彈】未命中。" << endl;
                turn.swap(); // 沒中換人
            }
        }
    }
}

void Game::initPlayers() {
    cout << "--- P1 選角（請輸入角色編號） ---" << endl;
    player1.chooseCharacter();
    cout << "--- P2 選角（請輸入角色編號） ---" << endl;
    player2.chooseCharacter();
}

void Game::chooseFirst() {
    srand((unsigned)time(nullptr));
    if(rand() % 2) {
        cout << ">> P1 先攻" << endl;
        turn.initTurn(player1, player2);
    } else { 
        cout << ">> P2 先攻" << endl;
        turn.initTurn(player2, player1);
    }
}

void Game::startRound() {
    // 若沒子彈則重填
    if (!gun.hasNext()) {
        cout << "=== 彈藥耗盡，重填 ===" << endl;
        gun.generate(REAL_AMMO, BLANK_AMMO);
    }
}

void Game::endGame() {
    cout << "\n========== GAME OVER ==========" << endl;
    if (player1.isDead()) cout << "Player 2 獲勝！" << endl;
    else cout << "Player 1 獲勝！" << endl;
}