#include "zombie.h"
#include "plant.h"
/*
 *  int attack;//攻击力
    int counter;//前进/攻击计数器
    int time;//前进/攻击间隔
    qreal speed;//每次运动时往前走的像素

    QMovie *body;//xxx.gif
    QMovie *head;//xxx.gif

    int state;//状态：0：初始状态 其他：不同僵尸有所不同
    int health;//剩余生命值
 */

Zombie::Zombie(QString _name,QString path)
{
    name=_name;

    attack=0;
    counter=0;
    time=0;
    speed=0;

    body=new QMovie(path);
    body->start();
    head=nullptr;

    state=0;
    health=0;
    basketball=0;

    if_slow=false;
    if_jump=false;
}

Zombie::~Zombie()
{
    delete body;
    delete head;
}

int Zombie::type() const
{
    return Type;
}

void Zombie::setBody(QString path)
{
    if (body)
        delete body;
    body = new QMovie(path);
    body->start();
}

void Zombie::setHead(QString path)
{
    if (head)
        delete head;
    head = new QMovie(path);
    head->start();
}

QRectF Zombie::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //body.gif
    QImage image = body->currentImage();
    if (if_slow&&(!(name=="ClownZombie"&&state==1)))//被snowpea击中过
    {
        int w = image.width();
        int h = image.height();
        for (int i = 0; i < h; ++i)//变成蓝色
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < w - 5; ++j)
                line[j << 2] = 200;
        }
    }
    if(state==5)
        painter->drawImage(QRectF(-100, -100, 200, 140), image);
    else if(name=="NewspaperZombie")
        painter->drawImage(QRectF(-100, -100, 160, 140), image);
    else if(name=="PoleVaultingZombie"&&state==0)
        painter->drawImage(QRectF(-100, -100, 200, 140), image);
    else
        painter->drawImage(QRectF(-70, -100, 140, 140), image);

    if (head)
    {
        image = head->currentImage();
        if (if_slow)
        {
            int w = image.width();
            int h = image.height();
            for (int i = 0; i < h; ++i)
            {
                uchar *line = image.scanLine(i);
                for (int j = 5; j < w - 5; ++j)
                    line[j << 2] = 200;
            }
        }
        painter->drawImage(QRectF(0, -100, 140, 140), image);
    }
}

bool Zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //左30像素内有无植物
    return other->type() == Plant::Type && qAbs(other->y()-y())<30 && qAbs(x()-other->x()) < 30&&other->x()<x();
}
