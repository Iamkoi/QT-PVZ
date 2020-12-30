#ifndef PEA_NORMAL_H
#define PEA_NORMAL_H
#include "pea.h"

class Pea_Normal : public Pea
{
public:
    Pea_Normal();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

#endif // PEA_NORMAL_H
