#include "pea.h"
#include"zombie.h"
/*
 *  int attack;
    QString name;
    qreal speed;
    int goal_x;//目标x，篮球用，其余为0
    int goal_y;//目标y，篮球用，其余为0
*/

Pea::Pea(QString _name)
{
    attack=0;
    name=_name;
    speed=360.0 * 33 / 1000;
    goal_x=0;
    goal_y=0;
}

int Pea::type() const
{
    return Type;
}

QRectF Pea::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap("://PVZ_Images/Peas/"+name+".png"));
}
