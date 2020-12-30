#ifndef NEWSPAPERZOMBIE_H
#define NEWSPAPERZOMBIE_H
#include "zombie.h"

class NewspaperZombie : public Zombie
{
public:
    NewspaperZombie();
    void advance(int phase) override;
};

#endif // NEWSPAPERZOMBIE_H
