#ifndef BASKETBALL_H
#define BASKETBALL_H
#include "pea.h"

class Basketball : public Pea
{
public:
    Basketball(int x,int y);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase)override;
};

#endif // BASKETBALL_H
