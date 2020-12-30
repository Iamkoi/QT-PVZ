#include "newspaperzombie.h"
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
//state;//状态：0：初始状态 1：丢掉报纸状态 2：攻击状态 3：死亡状态
NewspaperZombie::NewspaperZombie():Zombie("NewspaperZombie","://PVZ_Images/Zombies/NewspaperZombie/NewspaperZombie_body0.gif")
{
    attack=100*33/1000;
    speed=(80*33)/(4.7*1000);//4.7秒走完一格   狂暴后约1.8秒走完一格
    health = 420;
}

void NewspaperZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (health <= 0)//僵尸死亡
    {
        if(state==5)//bomb
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 3)//目前动画并非state3
        {
            state = 3;
            setBody("://PVZ_Images/Zombies/Zombie_body_die.gif");
            setHead("://PVZ_Images/Zombies/Zombie_body_head.gif");
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1
                 ||head->currentFrameNumber()==head->frameCount())//目前动画为state3且动画播放到了最后
            delete this;
        return;
    }

    else
    {
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty())//有碰撞，转到攻击状态state2
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

            if ((state==0||state==1)&&plant->state==0)//非攻击状态且植物是初始状态，转攻击状态state2
            {
                state = 2;
                setBody("://PVZ_Images/Zombies/NewspaperZombie/NewspaperZombie_body2.gif");
            }

            if(plant->state!=0)//植物正在爆炸/跳起来...
                setX(x() - speed);//前进
            return;
        }

        else//无碰撞
        {
            if(state==0)
            {
                if(health<=270)//转为丢掉报纸状态state1
                {
                    state=1;
                    setBody("://PVZ_Images/Zombies/NewspaperZombie/NewspaperZombie_body1.gif");
                    speed=(80*33)/(1.8*1000);//狂暴后约1.8秒走完一格
                }
            }

            else if(state==2)//攻击状态
            {
                if(health>270)//转state0
                {
                    state=0;
                    setBody("://PVZ_Images/Zombies/NewspaperZombie/NewspaperZombie_body0.gif");
                }
                else//转state1
                {
                    state=1;
                    setBody("://PVZ_Images/Zombies/NewspaperZombie/NewspaperZombie_body1.gif");
                    speed=(80*33)/(1.8*1000);//狂暴后约1.8秒走完一格
                }
            }
            setX(x() - speed);//前进
        }
    }
}
