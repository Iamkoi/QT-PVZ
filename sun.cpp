#include "sun.h"
#include "shop.h"
#include <QDebug>

/*
 *  QMovie *movie;//sun.gif
    qreal maxY;//最大的Y，到达之后停滞
    int counter;//阳光存在时间计数器
    int time;//阳光存在时间限制
    qreal speed;//阳光每次移动距离
 */

Sun::Sun()//用于系统产生阳光
{
    maxY=130 + qrand() % (98 * 5);
    movie=new QMovie("://PVZ_Images/Shop/Sun.gif");
    movie->start();

    counter=0;
    time = int(10.0 * 1000 / 33);
    speed = 60.0 * 50 / 1000;

    setPos(QPointF(290 + qrand() % (82 * 7),70));
}
Sun::Sun(QPointF pos)//用于向日葵产生阳光
{
    maxY=pos.y() + qrand() % 30 + 15;
    movie=new QMovie("://PVZ_Images/Shop/Sun.gif");
    movie->start();

    counter=0;
    time = int(10.0 * 1000 / 33);
    speed = 60.0 * 50 / 1000;

    setPos(QPointF(pos.x() + qrand() % 30 - 15,pos.y()));
}
Sun::~Sun()//将新new的东西删掉
{
    if(movie!=nullptr)
        delete movie;
}

QRectF Sun::boundingRect()const
{
    return QRectF(-35, -35, 70, 70);
}
void Sun::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawImage(boundingRect(), movie->currentImage());
}
void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
    shop->sun += 25;
    //qDebug()<<"sun="<<shop->sun;
    counter = time;//下一次advance函数里就会delete this
    event->setAccepted(true);
}
void Sun::advance(int phase)
{
    if (!phase)
        return;
    update();//重画该矩形框内的东西
    if (++counter >= time)
        delete this;
    else if (y() < maxY)
        setY(y() + speed);
}
int Sun::type() const
{
    return Type;
}
