#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include "plant.h"

class PeaShooter : public Plant
{
public:
    PeaShooter();
    void advance(int phase)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // PEASHOOTER_H
