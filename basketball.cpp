#include "basketball.h"
#include "zombie.h"
#include "plant.h"
/*
    QString name;
    qreal speed;

    int attack;
    int goal_x;//目标x，篮球用，其余为0
    int goal_y;//目标y，篮球用，其余为0
*/
Basketball::Basketball(int x,int y):Pea("Basketball")
{
    attack=20;
    speed=800.0 * 33 / 1000;
    goal_x=x;
    goal_y=y;
}

bool Basketball::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //同一行，x距离小于15、y距离小于15且在篮球左侧的植物
    return other->type() == Plant::Type && qAbs(other->x() - x()) < 15 && qAbs(other->x() - x()) < 15 &&other->x()<x();
}

void Basketball::advance(int phase)
{
    if (!phase)
        return;
    update();

    if(qAbs(x()-goal_x)<13&&(y()!=goal_y))//到达目的地但不在同一行
    {
        setPos(goal_x,goal_y);
        return;
    }
    else if(x()==goal_x&&y()==goal_y)
    {
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {
            Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);

            if(items.size()>=1)
            {
                Plant *temp=qgraphicsitem_cast<Plant *>(items[1]);
                if(qAbs(temp->x()-plant->x())<5&&temp->name=="Pumpkin")//南瓜头
                    plant=temp;
            }

            plant->health -= attack;
        }
        delete this;
        return;
    }
    else//还在飞行过程中
        setX(x() - speed);

    if (x() < -450)
        delete this;

    return;
}
