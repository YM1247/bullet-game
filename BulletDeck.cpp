#include "BulletDeck.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

BulletDeck::BulletDeck() : bullets()
{
	index = 0;
	bulletCnt = 0;
}
BulletDeck::~BulletDeck() {}

void BulletDeck::generate(int realCount, int blankCount) {
	int bulletCnt = realCount + blankCount;
    bullets.clear();
    index = 0;

    // 將彈匣充到指定數量
    for (int i = 0; i < realCount; i++) {
        bullets.push_back(1);   // 實彈
    }
    for (int i = 0; i < blankCount; i++) {
        bullets.push_back(0);  // 空彈
    }
	
	// seed 一次
	srand(time(0));

	std::vector<bool> temp = bullets; // 利用 bullets 複製另一個 temp 彈匣供隨機排序用
    bullets.clear(); // 清空 bullets 彈匣
    bullets.reserve(bulletCnt); // 幫 bullets 彈匣預留子彈空間

    while (!temp.empty()) {
        int idx = rand() % temp.size(); // 在目前 temp 彈匣內的子彈數量中隨機選出其中一個 index
        bullets.push_back(temp[idx]); // 將該 index 對應的子彈放進 bullets 彈匣
        temp.erase(temp.begin() + idx); // 將同顆子彈從 temp 彈匣中移除
	}
}

bool BulletDeck::fire() {
    if (!hasNext()) { // 若沒子彈了，啥也射不出來
		return false;
	}

    bool isReal = bullets[index];
    ++index;
    return isReal; // 回傳實彈或是虛彈
}

bool BulletDeck::hasNext() const { 
	return index < bulletCnt; // false if no more bullets
}

bool BulletDeck::isRealBullet() const {
    if (!hasNext()) { // 沒子彈也 return false
        return false;
    }
    return bullets[index];
}
