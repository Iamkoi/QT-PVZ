#include "snowpea.h"
#include "zombie.h"

SnowPea::SnowPea():Plant ("SnowPea","://PVZ_Images/Plants_gif/SnowPea.gif")
{
    health=300;
    time=int(1.4 * 1000 / 33);
}

void SnowPea::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            Pea_Snow *pea_snow=new Pea_Snow();
            pea_snow->setX(x()+35);
            pea_snow->setY(y());
            scene()->addItem(pea_snow);
            return;
        }
    }
}

bool SnowPea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qAbs(other->y()-y())<30 &&other->x()>x()&&other->x()-x()>30;
}

