#include "clownzombie.h"
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
//state;//状态：0：初始状态 1：爆炸状态 2：攻击状态 3：正常死亡状态

ClownZombie::ClownZombie():Zombie("ClownZombie","://PVZ_Images/Zombies/ClownZombie/ClownZombie_body0.gif")
{
    attack=100*33/1000;
    speed=(80*33)/(2.2*1000);//2.2秒走完一格
    health = 500;
}

void ClownZombie::advance(int phase)
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

    else if(state==1)//目前在播放爆炸动画
    {
        if (body->currentFrameNumber() == body->frameCount() - 1)//目前动画为state1且动画播放到了最后
        {
            QList<QGraphicsItem *> items = collidingItems();
            if(!items.isEmpty())//周围3*3格子有植物
            {
                //依次删除这些植物
                for(int i=0;i<items.size();i++)
                    delete items[i];
            }
            delete this;
        }
        return;
    }

    else//初始状态或攻击状态
    {
        int rd=qrand()%500;//1/500的概率会爆炸
        if(rd==0)//爆炸  转state1
        {
            state=1;
            setBody("://PVZ_Images/Zombies/ClownZombie/ClownZombie_body1.gif");
            return;
        }
        else//不爆炸，判断是否碰撞，碰撞则转state2进行攻击
        {
            QList<QGraphicsItem *> items = collidingItems();
            Plant *plant=nullptr;
            if(!items.isEmpty())//有碰撞,找要攻击的植物
            {
                for(int j=items.size()-1;j>=0;j--)
                {
                    if(items[j]->y()==y()&&items[j]->x()<x())//找到
                    {
                        plant=qgraphicsitem_cast<Plant *>(items[j]);
                        break;
                    }
                }
            }

            if(plant)//有碰撞,攻击
            {
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

                if(state!=2)//非攻击状态
                {
                    state = 2;
                    setBody("://PVZ_Images/Zombies/ClownZombie/ClownZombie_body2.gif");
                }
                return;
            }
            //无碰撞，继续前进
            if(state!=0)
            {
                state=0;
                setBody("://PVZ_Images/Zombies/ClownZombie/ClownZombie_body0.gif");
            }
            setX(x() - speed);//前进
        }
    }
}

bool ClownZombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //周围3*3内有无植物
    return other->type() == Plant::Type && qAbs(other->y() - y()) <100 && qAbs(other->x() - x()) <50;
}
