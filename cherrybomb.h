#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include "plant.h"

class CherryBomb : public Plant
{
public:
    CherryBomb();
    void advance(int phase) override;
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // CHERRYBOMB_H
