#ifndef PEA_SNOW_H
#define PEA_SNOW_H
#include "pea.h"

class Pea_Snow : public Pea
{
public:
    Pea_Snow();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

#endif // PEA_SNOW_H
