#ifndef BULLETDECK_H
#define BULLETDECK_H

#include <vector>

class BulletDeck {
    private:
    std::vector<bool> bullets;
    int index; //下一發的位置

    char pointingDirection; // pointing to which player?

    public:
    BulletDeck();
    ~BulletDeck();
    void generate(int realCount, int blankCount);
    bool fire();               // 回傳是否是實彈
    bool hasNext();            // 還有沒有下一發

    void fixedDirection(Player *opponent); // for BigJ's skill ?
};

#endif