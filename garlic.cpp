#include "garlic.h"
#include "zombie.h"

Garlic::Garlic():Plant ("Garlic","://PVZ_Images/Plants_gif/Garlic.gif")
{
    health=400;
    time=0;
}

void Garlic::advance(int phase)
{
    if (!phase)
        return;
    update();

    if (133 < health && health <= 266)//被啃食阶段一
    {
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/Garlic1.gif");
        movie->start();
    }
    else if (health <= 133&&health>0)//被啃食阶段二
    {
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/Garlic2.gif");
        movie->start();
    }
    else if(health<=0)//植物死亡
        delete this;
}
