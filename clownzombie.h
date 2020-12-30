#ifndef CLOWNZOMBIE_H
#define CLOWNZOMBIE_H
#include "zombie.h"

class ClownZombie : public Zombie
{
public:
    ClownZombie();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // CLOWNZOMBIE_H
