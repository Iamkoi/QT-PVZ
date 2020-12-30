#include "squash.h"
#include "zombie.h"

Squash::Squash():Plant ("Squash","://PVZ_Images/Plants_gif/Squash.gif")
{
    health=300;
    time=0;
}

QRectF Squash::boundingRect() const
{
    return QRectF(-35, -42, 70, 84);
}

//state:  0:未跳起 1：已跳起
void Squash::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)
    {
        delete this;
        return;
    }
    else if (++counter >= time)//可以攻击僵尸
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())//右边格子有僵尸
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
            if(state==0)
            {
                state=1;
                zombie->health=0;
                setX(zombie->x());
                if(movie)
                    delete movie;
                movie=new QMovie("://PVZ_Images/Plants_gif/Squash1.gif");
                movie->start();
                return;
            }
            return;
        }
        if(state==1&&movie->currentFrameNumber()==movie->frameCount()-1)//攻击状态，且播放到了最后
            delete this;
        return;
    }
}

bool Squash::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //右边30个像素里有僵尸
    return other->type() == Zombie::Type && qAbs(other->y()-y())<30 && other->x() - x() < 80&&other->x()>x();
}
