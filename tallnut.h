#ifndef TALLNUT_H
#define TALLNUT_H
#include "plant.h"

class TallNut : public Plant
{
public:
    TallNut();
    QRectF boundingRect() const override;
    void advance(int phase) override;
};

#endif // TALLNUT_H
