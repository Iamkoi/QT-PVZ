#include "catapultzombie.h"
#include "plant.h"
#include "basketball.h"
/*
 *  attack=0;
    counter=0;//
    time=0;//
    speed=0;

    body=new QMovie(path);
    body->start();
    head=nullptr;

    state=0;//
    health=0;
 */
//state;//状态：0：静止投篮状态 1:投篮结束前进状态&攻击状态 2：死亡状态 5:bomb

CatapultZombie::CatapultZombie():Zombie("ClownZombie","://PVZ_Images/Zombies/CatapultZombie/CatapultZombie_body0.gif")
{
    attack=100*33/1000;
    speed=(80*33)/(2.5*1000);//2.5秒走完一格
    health = 850;
    basketball=10;
    time=int(1.4 * 1000 / 33);
}

void CatapultZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();

    if (health <= 0)//僵尸死亡
    {
        if(state==5)//bomb
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2)//目前动画并非state3
        {
            state = 2;
            setBody("://PVZ_Images/Zombies/Zombie_body_die.gif");
            setHead("://PVZ_Images/Zombies/Zombie_body_head.gif");
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1
                 ||head->currentFrameNumber()==head->frameCount())//目前动画为state2且动画播放到了最后
            delete this;
        return;
    }

    else if(state==0)//静止投篮状态
    {
        //如果本行没有植物，则转state1，前进
        if(items.isEmpty())
        {
            state=1;
            setBody("://PVZ_Images/Zombies/CatapultZombie/CatapultZombie_body1.gif");
            return;
        }

        //如果本行有植物，则往第一个植物items[0]处投篮，状态不变
        else
        {
            if(++counter>time)
            {
                counter=0;
                Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
                //新建篮球
                Basketball *basketball1 = new Basketball(plant->x(),plant->y());
                basketball1->setX(x()-32);
                basketball1->setY(y()-32);
                scene()->addItem(basketball1);

                basketball--;
                if(basketball==0)//如果篮球数变为0，则转state1
                {
                    state=1;
                    setBody("://PVZ_Images/Zombies/CatapultZombie/CatapultZombie_body1.gif");
                }
            }
            return;
        }
    }

    else if(state==1)//前进&攻击状态
    {
        //如果本行没有植物，则状态不变，前进
        if(items.isEmpty())
        {
            setX(x() - speed);//前进
            return;
        }

        //如果本行有植物
        else
        {
            if(basketball>0)//有篮球，转到state0
            {
                state=0;
                //setBody("://PVZ_Images/Zombies/CatapultZombie/CatapultZombie_body0.gif");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           b
                //return;
                setBody("://PVZ_Images/Zombies/CatapultZombie/CatapultZombie_body0.gif");
                //setBody("://PVZ_Images/Zombies/CatapultZombie/CatapultZombie_body0.gif");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           b
                return;
            }

            else//没有篮球，保持原状态，前进
            {
                setX(x() - speed);//前进
                return;
            }
        }
    }
}

bool CatapultZombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //本行有无植物
    return other->type() == Plant::Type && qAbs(other->y()-y())<10&&other->x()<x();
}
