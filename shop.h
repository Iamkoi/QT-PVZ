#ifndef SHOP_H
#define SHOP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

#include "sun.h"
#include "myitem.h"

class Shop : public MyItem
{
private:
    int counter;//系统产生阳光的计时器
    int time;//系统产生阳光的要求时间
public:
    int sun;//阳光数

    Shop();
    void addPlant(QString s, QPointF pos);//购买植物并种植

    QRectF boundingRect()const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void advance(int phase)override;
};

#endif // SHOP_H
