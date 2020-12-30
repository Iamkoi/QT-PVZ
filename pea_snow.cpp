#include "pea_snow.h"
#include "zombie.h"
/*
    QString name;
    qreal speed;

    int attack;
    int goal_x;//目标x，篮球用，其余为0
    int goal_y;//目标y，篮球用，其余为0
*/
Pea_Snow::Pea_Snow():Pea("Pea_Snow")
{
    attack=25;
}

bool Pea_Snow::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //同一行，距离小于15且在豌豆右侧的僵尸
    return other->type() == Zombie::Type && qAbs(other->y()-y())<5 && qAbs(other->x() - x()) < 15 &&other->x()>x();
}

void Pea_Snow::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
        zombie->health -= attack;
        if(!zombie->if_slow)
        {
            zombie->speed/=2;
            zombie->if_slow=true;
        }
        delete this;
        return;
    }
    setX(x() + speed);
    if (x() > 1069)
        delete this;
}
