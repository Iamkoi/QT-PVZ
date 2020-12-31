#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    //背景图
    scene=new QGraphicsScene(this);
    scene->setSceneRect(150,0,900,600);
    scene->setBackgroundBrush(QPixmap("://PVZ_Images/Background.jpg"));
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setFixedSize(900,600);

    //计时器
    timer=new QTimer;
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::addZombie);
    connect(timer, &QTimer::timeout, this, &MainWindow::check_gameover);
    timer->start(33);//每隔33毫秒timeout一次，调用一次advance函数

    //商店
    shop = new Shop;
    shop->setPos(520, 45);
    scene->addItem(shop);

    //绿地
    Map *map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);

    view=new QGraphicsView(this);
    view->setScene(scene);
    view->resize(902,602);
    view->show();
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
    delete shop;
}

void MainWindow::addZombie()
{
    static int time = 10 * 1000 / 33;//TODO
    static int counter = 0;

    if (++counter >= time)
    {
        counter=0;
        int create=qrand() % 2;
        if(create==0)
            return;

        int type = qrand() % 10;//类型
        int i = qrand() % 5;//行

        Zombie *zombie;

        if (type <=4)
            zombie = new NormalZombie;
        else if (type <=5)
            zombie = new ConeheadZombie;
        else if (type <=6)
            zombie = new NewspaperZombie;
        else if (type <=7)
            zombie = new PoleVaultingZombie;
        else if (type <=8)
            zombie = new ClownZombie;
        else
            zombie = new CatapultZombie;

        zombie->setPos(1028, 130 + 98 * i);
        scene->addItem(zombie);
    }
}

void MainWindow::check_gameover()
{
    static int time = 1 * 1000 / 33;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
            if (item->type() == Zombie::Type && item->x() < 200)
            {
                scene->addPixmap(QPixmap("://PVZ_Images/ZombiesWon.png"))->setPos(336, 92);
                scene->advance();
                timer->stop();
                return;
            }
    }
}
