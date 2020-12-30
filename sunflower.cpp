#include "sunflower.h"
#include "sun.h"

SunFlower::SunFlower():Plant ("SunFlower","://PVZ_Images/Plants_gif/SunFlower.gif")
{
    health=300;
    time=int(12.0 * 1000 / 33);
}
void SunFlower::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)
        delete this;
    else if (++counter >= time)//产生阳光
    {
        counter = 0;
        scene()->addItem(new Sun(pos()));
    }
}
