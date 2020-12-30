#ifndef GARLIC_H
#define GARLIC_H
#include "plant.h"

class Garlic : public Plant
{
public:
    Garlic();
    void advance(int phase) override;
};

#endif // GARLIC_H
