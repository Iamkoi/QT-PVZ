#ifndef CARD_H
#define CARD_H

#include <QGraphicsItem>
#include "myitem.h"

class Card : public MyItem
{
public:
    int num;//0~9,代表从左到右十个植物
    int counter;//冷却时间的计时
    static QVector<QString> name;//用于寻找png
    static QVector<int> cost;//购买所需花费，用于显示在卡片上以及购买时扣除阳光数
    static QVector<int> cool;//冷却时间，用于形成QBrush的黑色遮罩
    static QVector<int> pos_x;//卡片位置x坐标
    static int pos_y;//卡片位置y坐标

    Card(int n);

    QRectF boundingRect()const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void advance(int phase) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CARD_H
