#ifndef SQUASH_H
#define SQUASH_H
#include "plant.h"

class Squash : public Plant
{
public:
    Squash();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // SQUASH_H
