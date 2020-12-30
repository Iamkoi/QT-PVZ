#include "cherrybomb.h"
#include "zombie.h"

CherryBomb::CherryBomb():Plant ("CherryBomb","://PVZ_Images/Plants_gif/CherryBomb.gif")
{
    health=300;
    time=0;
}

QRectF CherryBomb::boundingRect() const
{
    if(state==0)//初始状态
        return QRectF(-35, -35, 70, 70);
    else
        return QRectF(-150, -150, 300, 300);
}

//state: 0:膨胀 1：爆炸
void CherryBomb::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)
        delete this;
    else if (state == 0 && movie->currentFrameNumber() == movie->frameCount() - 1)//转state1
    {
        state = 1;
        if(movie)
            delete movie;
        movie=new QMovie("://PVZ_Images/Plants_gif/CherryBomb1.gif");
        movie->start();

        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->health=0;
            zombie->state=5;
            zombie->setBody("://PVZ_Images/Zombies/Zombie_bomb.gif");
        }
    }
    else if (state == 1 && movie->currentFrameNumber() == movie->frameCount() - 1)//结束
        delete this;

    return;
}

bool CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //周围9个格子里有僵尸
    return other->type() == Zombie::Type && qAbs(other->y() - y()) <100 && qAbs(other->x() - x()) <85;
}
