#-------------------------------------------------
#
# Project created by QtCreator 2012-12-11T19:56:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    food.cpp \
    snake.cpp \
    wall.cpp \
    states/food/eatedstate.cpp \
    states/snake/movingstate.cpp \
    states/snake/eatingstate.cpp \
    states/food/foodwaitingstate.cpp \
    states/snake/hittingsomethingstate.cpp \
    observer/leftkeyobserver.cpp \
    observer/rightkeyobserver.cpp \
    observer/downkeyobserver.cpp \
    observer/upkeyobserver.cpp

HEADERS  += mainwindow.h \
    food.h \
    constants.h \
    snake.h \
    wall.h \
    states/state.h\
    observer/observer.h \
    element.h \
    states/food/eatedstate.h \
    states/snake/movingstate.h \
    states/snake/eatingstate.h \
    states/food/foodwaitingstate.h \
    states/snake/hittingsomethingstate.h \
    observer/leftkeyobserver.h \
    observer/rightkeyobserver.h \
    observer/downkeyobserver.h \
    observer/upkeyobserver.h
