#include "polevaultingzombie.h"
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
//state;//状态：0：初始状态 1：跳过第一个植物状态 2：攻击状态 3：死亡状态
PoleVaultingZombie::PoleVaultingZombie():Zombie("PoleVaultingZombie","://PVZ_Images/Zombies/PoleVaultingZombie/PoleVaultingZombie_body0.gif")
{
    attack=100*33/1000;
    speed=(80*33)/(2.5*1000);//2.5秒走完一格   跳跃后约4.5秒走完一格
    health = 500;
}

void PoleVaultingZombie::advance(int phase)
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
        if(!items.isEmpty())//有碰撞，判断是否是高坚果，若是则转攻击状态；否则：若是state0则跳过去并转state1，若是state1则攻击
        {
            Plant *plant = qgraphicsitem_cast<Plant *>(items[items.size()-1]);
            if(plant->name=="TallNut"||if_jump)//不能跳过：高坚果或之前已经跳过一个植物
            {
                plant->health -= attack;//攻击植物
                if(plant->name=="Garlic")//驱赶到邻近行
                {
                    int now_line=(int(y())-81)/98;
                    if(now_line==0) setY(y()+98);
                    else if(now_line==4) setY(y()-98);
                    else
                    {
                        int m=qrand()%2;
                        if(m) setY(y()+98);
                        else setY(y()-98);
                    }
                }
                if(state!=2)//非攻击状态
                {
                    state = 2;
                    setBody("://PVZ_Images/Zombies/PoleVaultingZombie/PoleVaultingZombie_body2.gif");
                }
                return;
            }
            //可以跳过
            else if(state==0)//跳过去并转state1
            {
                if_jump=true;
                setX(x() - 120);//前进
                state=1;
                speed=(80*33)/(4.5*1000);//跳跃后约4.5秒走完一格
                setBody("://PVZ_Images/Zombies/PoleVaultingZombie/PoleVaultingZombie_body1.gif");
                return;
            }
        }
        //无碰撞，继续前进
        if(state==2)
        {
            if(if_jump)
            {
                state=1;
                setBody("://PVZ_Images/Zombies/PoleVaultingZombie/PoleVaultingZombie_body1.gif");
            }
            else
            {
                state=0;
                setBody("://PVZ_Images/Zombies/PoleVaultingZombie/PoleVaultingZombie_body0.gif");
            }
        }
        setX(x() - speed);//前进
    }
}
