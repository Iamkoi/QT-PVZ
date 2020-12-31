#ifndef CATAPULTZOMBIE_H
#define CATAPULTZOMBIE_H
#include "zombie.h"

class CatapultZombie : public Zombie
{
public:
    CatapultZombie();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // CATAPULTZOMBIE_H
