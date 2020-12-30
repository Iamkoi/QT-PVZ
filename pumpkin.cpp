#include "pumpkin.h"

Pumpkin::Pumpkin():Plant ("Pumpkin","://PVZ_Images/Plants_gif/Pumpkin.gif")
{
    health=4000;
    time=0;
}

void Pumpkin::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (1333 < health && health <= 2666)//被啃食阶段一
    {
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/Pumpkin1.gif");
        movie->start();
    }
    else if (health <= 1333&&health>0)//被啃食阶段二
    {
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/Pumpkin2.gif");
        movie->start();
    }
    else if(health<=0)//植物死亡
        delete this;
}
