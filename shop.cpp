#include "shop.h"
#include "card.h"
#include "plant.h"

#include "sunflower.h"
#include "peashooter.h"
#include "repeater.h"
#include "snowpea.h"
#include "wallnut.h"
//#include "tallnut.h"
//#include "squash.h"
//#include "cherrybomb.h"
//#include "garlic.h"
//#include "pumpkin.h"

#include <QDebug>

Shop::Shop()
{
    counter=0;//系统产生阳光的计时器
    time=int(7.0 * 1000 / 33);;//系统产生阳光的要求时间
    sun=200;//阳光数

    Card *card = nullptr;
    for (int i = 0; i < 10; ++i)
    {
        card = new Card(i);
        card->setParentItem(this);
        card->setPos(-165 + 60 * i, -2);
    }
}

void Shop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);//获取该位置所有Item
    for(int i=0;i<items.size();i++)
    {
        if(items[i]->type()==Plant::Type)//该地块已有植物,失败
        {
            Plant *plant = qgraphicsitem_cast<Plant *>(items[i]);//该植物
            if((plant->name=="Pumpkin")==(s=="Pumpkin"))//二者都是南瓜头或者都不是南瓜头，则无法种植，失败
                return;
        }
    }

    //根据名字找植物类型
    int plant_num=-1;//0~9
    for(int i=0;i<10;i++)
    {
        if(Card::name[i]==s)//找到
        {
            plant_num=i;
            break;
        }
    }

    sun -= Card::cost[plant_num];//消耗阳光

    Plant *plant = nullptr;
    switch (plant_num)//选择植物
    {
    case 0:
        plant = new SunFlower; break;
    case 1:
        plant = new PeaShooter; break;
    case 2:
        plant = new Repeater; break;
    case 3:
        plant = new SnowPea; break;
    case 4:
        plant = new WallNut; break;
//    case 5:
//        plant = new TallNut; break;
//    case 6:
//        plant = new Squash; break;
//    case 7:
//        plant = new CherryBomb; break;
//    case 8:
//        plant = new Garlic; break;
//    case 9:
//        plant = new Pumpkin; plant->setX(x()+5); break;
    default:break;
    }

    plant->setPos(pos);//植物位置
    scene()->addItem(plant);
    //qDebug()<<"addPlant_pos:"<<plant->x()<<","<<plant->y();

    QList<QGraphicsItem *> tempcards = childItems();
    for(int i=0;i<tempcards.size();i++)
    {
        Card *card = qgraphicsitem_cast<Card *>(tempcards[i]);
        if (card->num == plant_num)
            card->counter = 0;//冷却时间计时
    }
}

QRectF Shop::boundingRect()const
{
    return QRectF(-280,-45,600,90);
}

void Shop::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //商店背景图
    painter->drawPixmap(QRect(-280, -45, 700, 86), QPixmap("://PVZ_Images/Shop/Shop.png"));

    //打印阳光数
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-276, 17, 70, 22), Qt::AlignCenter, QString::number(sun));
}

void Shop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)//系统产生阳光
    {
        counter = 0;
        scene()->addItem(new Sun);
    }
}

