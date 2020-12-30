#include "plant.h"
#include "zombie.h"
/*
 *  int health;//剩余生命值
    int attack;//攻击力
    int counter;//攻击计数器
    int time;//攻击间隔
    QMovie *movie;//xxx.gif
 */

Plant::Plant(QString _name,QString path)
{
    name=_name;

    movie=new QMovie(path);
    movie->start();

    health=0;
    attack=0;
    counter=0;
    time=0;

    state=0;
}

Plant::~Plant()
{
    delete movie;
}

int Plant::type() const
{
    return Type;
}

QRectF Plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(), movie->currentImage());
}

bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qAbs(other->y()-y())<30 && qAbs(other->x()-x()) < 30 && other->x()>x();
}

