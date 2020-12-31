#include "card.h"
#include "shop.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QWidget>

QVector<QString> Card::name = {"SunFlower", "PeaShooter", "Repeater", "SnowPea", "WallNut",
                               "TallNut", "Squash", "CherryBomb", "Garlic", "Pumpkin"};
QVector<int> Card::cost = {50,100,200,175,50,125,50,150,50,125};
//QVector<double> Card::cool = {7.5,7.5,7.5,7.5,30, 30,30,50,7.5,30};//单位：秒
QVector<int> Card::cool = {225,225,225,225,900, 900,900,1500,225,900};//单位：秒/30
//QVector<int> Card::cool = {0,0,0,0,0, 0,0,0,0,0};//单位：秒/30
QVector<int> Card::pos_x={180,210,300,360,420,480,540,600,660,720};
int Card::pos_y=4;
//宽：60 高：70

Card::Card(int n)
{
    num=n;
    counter=0;
}

QRectF Card::boundingRect()const
{
    return QRectF(-30, -35, 60, 70);
}

void Card::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //打印卡片
    painter->drawPixmap(QRect(-30, -35, 60, 70), QPixmap("://PVZ_Images/Cards/" + name[num] + ".png"));

    //打印冷却时间的黑色蒙版
    if (counter < cool[num])
    {
        QBrush brush(QColor(0, 0, 0, 200));//黑色蒙版
        painter->setBrush(brush);
        painter->drawRect(QRect(-30, -35, 60, 70 * (1 - qreal(counter) / cool[num])));
    }
}

void Card::advance(int phase)
{
    if (!phase)
        return;
    update();//重画该矩形框内的东西
    if (counter < cool[num])
        ++counter;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //冷却状态不可按
    if (counter < cool[num])
        event->setAccepted(false);

    //阳光数过少不可按
    Shop *shop = qgraphicsitem_cast<Shop *>(parentItem());
    if (cost[num] > shop->sun)
        event->setAccepted(false);
}
void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()< QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image("://PVZ_Images/Plants_png/" + name[num] + ".png");

    mime->setText(name[num]);
    mime->setImageData(image);

    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(30, 35));
    drag->exec();
}
