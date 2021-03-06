#-------------------------------------------------
#
# Project created by QtCreator 2020-12-30T11:07:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT-PVZ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    myitem.cpp \
    shop.cpp \
    sun.cpp \
    map.cpp \
    card.cpp \
    plant.cpp \
    zombie.cpp \
    peashooter.cpp \
    normalzombie.cpp \
    pea.cpp \
    pea_normal.cpp \
    sunflower.cpp \
    repeater.cpp \
    snowpea.cpp \
    pea_snow.cpp \
    wallnut.cpp \
    tallnut.cpp \
    squash.cpp \
    cherrybomb.cpp \
    garlic.cpp \
    pumpkin.cpp \
    coneheadzombie.cpp \
    newspaperzombie.cpp \
    polevaultingzombie.cpp \
    clownzombie.cpp \
    catapultzombie.cpp \
    basketball.cpp

HEADERS += \
        mainwindow.h \
    myitem.h \
    shop.h \
    sun.h \
    map.h \
    card.h \
    plant.h \
    zombie.h \
    peashooter.h \
    normalzombie.h \
    pea.h \
    pea_normal.h \
    sunflower.h \
    repeater.h \
    snowpea.h \
    pea_snow.h \
    wallnut.h \
    tallnut.h \
    squash.h \
    cherrybomb.h \
    garlic.h \
    pumpkin.h \
    coneheadzombie.h \
    newspaperzombie.h \
    polevaultingzombie.h \
    clownzombie.h \
    catapultzombie.h \
    basketball.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
