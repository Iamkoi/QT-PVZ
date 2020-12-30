#ifndef PEA_H
#define PEA_H
#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>
#include <QGraphicsScene>
#include <QString>

class Pea : public QGraphicsItem
{
protected:
    QString name;//Pea_Normal/Pea_Snow/Basketball
    qreal speed;//每次前进的像素
    int attack;//攻击力
public:
    int goal_x;//目标x，篮球用，其余为0
    int goal_y;//目标y，篮球用，其余为0

    Pea(QString _name);
    enum{Type=UserType+4};
    int type() const override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PEA_H
