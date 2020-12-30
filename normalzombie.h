#ifndef NORMALZOMBIE_H
#define NORMALZOMBIE_H
#include "zombie.h"

class NormalZombie : public Zombie
{
public:
     NormalZombie();
     void advance(int phase) override;
};

#endif // NORMALZOMBIE_H
