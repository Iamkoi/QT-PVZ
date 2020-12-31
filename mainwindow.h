#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "shop.h"
#include "map.h"
#include "card.h"

#include "normalzombie.h"
#include "coneheadzombie.h"
#include "newspaperzombie.h"
#include "polevaultingzombie.h"
#include "clownzombie.h"
#include "catapultzombie.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addZombie();
    void check_gameover();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Shop *shop;

    QTimer *timer;
};
#endif // MAINWINDOW_H
