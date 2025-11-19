#include "Player.h"

class TurnManager {
    private:
    Player *current;
    Player *opponent;

    public:
    void swap();     // 換人
    void grantExtraShot(Player& p);
    bool hasExtraShot(Player& p);
};