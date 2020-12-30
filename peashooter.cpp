#include "peashooter.h"
#include "zombie.h"
#include <QDebug>
/*
 *  int health;//剩余生命值
    int attack;//攻击力
    int counter;//攻击计数器
    int time;//攻击间隔
    QMovie *movie;//xxx.gif
 */

PeaShooter::PeaShooter():Plant ("PeaShooter","://PVZ_Images/Plants_gif/PeaShooter.gif")
{
    health=300;
    time=int(1.4 * 1000 / 33);
}

void PeaShooter::advance(int phase)
{
    if (!phase)
        return;
    update();
//    qDebug()<<"counter"<<counter;
    if (health <= 0)
        delete this;
    else if (++counter >= time)
    {
//        qDebug()<<"++counter >= time"<<counter;
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
//        for(int i=0;i<items.size();i++)
//            qDebug()<<"items["<<i<<"].type():"<<items[i]->type();
        if (!items.isEmpty())//有碰撞的僵尸
        {
//            qDebug()<<"!isEmpty()";
            Pea_Normal *pea_normal = new Pea_Normal();
            pea_normal->setX(x() + 35);
            pea_normal->setY(y());
            scene()->addItem(pea_normal);
            return;
        }
    }
}

bool PeaShooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
//    if(other->type()==Zombie::Type)
//    {
//        qDebug()<<"other"<<other->x()<<","<<other->y();
//        qDebug()<<"peashooter"<<x()<<","<<y();
//    }

    return other->type() == Zombie::Type && qAbs(other->y()-y())<30 &&other->x()>x();
}
