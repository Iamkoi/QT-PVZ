#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "shop.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
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
