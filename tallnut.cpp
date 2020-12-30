#include "tallnut.h"

TallNut::TallNut():Plant ("TallNut","://PVZ_Images/Plants_gif/TallNut.gif")
{
    health=8000;
    time=0;
}

QRectF TallNut::boundingRect() const
{
    return QRectF(-35, -45, 70, 90);
}

void TallNut::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (2666 < health && health <= 5333)//被啃食阶段一
    {
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/TallNut1.gif");
        movie->start();
    }
    else if (health <= 2666&&health>0)//被啃食阶段二
    {
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/TallNut2.gif");
        movie->start();
    }
    else if(health<0)//植物死亡
        delete this;
}
