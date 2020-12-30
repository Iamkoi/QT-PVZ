#ifndef MAP_H
#define MAP_H

#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsItem>
#include <QMimeData>

#include "shop.h"
#include "myitem.h"

class Map : public MyItem
{
public:
    Map();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
};

#endif // MAP_H
