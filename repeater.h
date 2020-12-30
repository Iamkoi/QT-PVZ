#ifndef REPEATER_H
#define REPEATER_H
#include "plant.h"

class Repeater : public Plant
{
public:
    Repeater();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // REPEATER_H
