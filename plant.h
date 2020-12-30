#ifndef PLANT_H
#define PLANT_H
#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>
#include <QGraphicsScene>

#include "pea_normal.h"
#include "pea_snow.h"
//#include "basketball.h"

class Plant : public QGraphicsItem
{
protected:
    int attack;//攻击力

    int counter;//攻击计数器
    int time;//攻击间隔

    QMovie *movie;//xxx.gif
public:
    QString name;
    int state;
    int health;//剩余生命值

    enum { Type = UserType + 1};
    int type() const override;

    Plant(QString _name,QString path);
    ~Plant() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};
#endif // PLANT_H
