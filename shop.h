#ifndef SHOP_H
#define SHOP_H
#include "myitem.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

//#include "sun.h"

class Shop : public MyItem
{
private:
    int counter;//系统产生阳光的计时器
    int time;//系统产生阳光的要求时间
public:
    int sun;//阳光数
    Shop();
    QRectF boundingRect()const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void advance(int phase)override;
    void addPlant(QString s, QPointF pos);
    int type() const override;
};

#endif // SHOP_H
