#ifndef CONEHEADZOMBIE_H
#define CONEHEADZOMBIE_H
#include "zombie.h"

class ConeheadZombie : public Zombie
{
public:
    ConeheadZombie();
    void advance(int phase) override;
};

#endif // CONEHEADZOMBIE_H
