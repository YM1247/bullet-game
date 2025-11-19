#include "Player.h"
#include "BulletDeck.h"

class Character {
    public:
    virtual ~Character();

    virtual void onShootSelf(Player& self, BulletDeck& deck);
    virtual void onShootEnemy(Player& enemy, BulletDeck& deck);
    virtual void onRoundStart(BulletDeck& deck);
    virtual void useSkill();
};

// other characters may be like:
class Elliot : public Character {};