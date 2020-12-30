#include "repeater.h"
#include "zombie.h"

Repeater::Repeater():Plant ("Repeater","://PVZ_Images/Plants_gif/Repeater.gif")
{
    health=300;
    time=int(1.4 * 1000 / 33);
}

void Repeater::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())//碰撞
        {
            Pea_Normal *pea_normal = new Pea_Normal();
            pea_normal->setX(x() + 35);
            pea_normal->setY(y());
            scene()->addItem(pea_normal);

            pea_normal = new Pea_Normal();
            pea_normal->setX(x() + 70);
            pea_normal->setY(y());
            scene()->addItem(pea_normal);

            return;
        }
    }
}

bool Repeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qAbs(other->y()-y())<30 &&other->x()>x()&&other->x()-x()>30;
}
