#include "normalzombie.h"
#include "plant.h"
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
//state;//状态：0：初始状态 1：攻击状态 2：死亡状态
NormalZombie::NormalZombie():Zombie("NormalZombie","://PVZ_Images/Zombies/NormalZombie/NormalZombie_body0.gif")
{
    attack=100*33/1000;
    speed=(80*33)/(4.7*1000);//4.7秒走完一格
    health = 270;
}

void NormalZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)
    {
        if(state==5)//bomb
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2)//目前动画并非state2
        {
            state = 2;
            setBody("://PVZ_Images/Zombies/Zombie_body_die.gif");
            setHead("://PVZ_Images/Zombies/Zombie_body_head.gif");
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1)//目前动画为state2且动画播放到了最后
            delete this;
        return;
    }

    else
    {
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())//有碰撞
        {
            Plant *plant = qgraphicsitem_cast<Plant *>(items[items.size()-1]);
            plant->health -= attack;//攻击植物
            if(plant->name=="Garlic")//驱赶到邻近行
            {
                int now_line=(int(y())-81)/98;
                if(now_line==0)
                    setY(y()+98);
                else if(now_line==4)
                    setY(y()-98);
                else
                {
                    int m=qrand()%2;
                    if(m)
                        setY(y()+98);
                    else
                        setY(y()-98);
                }
            }

            if (state==0&&plant->state==0)//初始状态且植物是初始状态，转攻击状态state1
            {
                state = 1;
                setBody("://PVZ_Images/Zombies/NormalZombie/NormalZombie_body1.gif");
            }

            if(plant->state!=0)//植物正在爆炸/跳起来...
                setX(x() - speed);//前进
            return;
        }

        else//无碰撞
        {
            if(state==1)//攻击状态，转state0
            {
                state=0;
                setBody("://PVZ_Images/Zombies/NormalZombie/NormalZombie_body0.gif");
            }
            setX(x() - speed);//前进
            return;
        }
    }
}
