#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class MyItem : public QGraphicsItem
{
public:
    enum { Type = UserType + 3};
    MyItem();
    int type() const override;
};

#endif // MYITEM_H
