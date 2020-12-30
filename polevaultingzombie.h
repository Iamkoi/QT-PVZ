#ifndef POLEVAULTINGZOMBIE_H
#define POLEVAULTINGZOMBIE_H
#include "zombie.h"

class PoleVaultingZombie : public Zombie
{
public:
    PoleVaultingZombie();
    void advance(int phase) override;
};

#endif // POLEVAULTINGZOMBIE_H
