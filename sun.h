#ifndef SUN_H
#define SUN_H
#include <QGraphicsItem>
#include <QMovie>
#include <QPointF>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

#include "myitem.h"

class Sun : public MyItem
{
private:
    QMovie *movie;//sun.gif
    qreal maxY;//最大的Y，到达之后停滞
    int counter;//阳光存在时间计数器
    int time;//阳光存在时间限制
    qreal speed;//阳光每次移动距离

public:
    Sun();
    Sun(QPointF pos);//用于向日葵产生阳光
    ~Sun() override;//将新new的东西删掉

    QRectF boundingRect()const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    void advance(int phase) override;
    int type() const override;
};

#endif // SUN_H
