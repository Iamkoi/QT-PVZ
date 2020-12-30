#ifndef PUMPKIN_H
#define PUMPKIN_H
#include "plant.h"

class Pumpkin : public Plant
{
public:
    Pumpkin();
    void advance(int phase) override;
};

#endif // PUMPKIN_H
