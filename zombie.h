#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QGraphicsItem>
#include <QMovie>
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>

class Zombie : public QGraphicsItem
{
protected:
    int attack;//攻击力
    int counter;//前进/攻击计数器
    int time;//前进/攻击间隔

    QMovie *body;//xxx.gif
    QMovie *head;//xxx.gif
public:
    qreal speed;//每次运动时往前走的像素
    QString name;

    int state;//状态：0：初始状态 1：攻击状态 2：死亡状态
    int health;//剩余生命值
    int basketball;//篮球数量
    bool if_slow;//是否已经被寒冰射手射中

    enum { Type = UserType + 2};
    int type() const override;

    Zombie(QString _name,QString path);
    ~Zombie() override;
    void setBody(QString path);
    void setHead(QString path);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // ZOMBIE_H
