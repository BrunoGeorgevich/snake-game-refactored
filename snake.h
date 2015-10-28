#ifndef SNAKE_H
#define SNAKE_H

#include "element.h"

#include "states/snake/movingstate.h"
#include "states/snake/eatingstate.h"
#include "states/snake/hittingsomethingstate.h"

#include "observer/downkeyobserver.h"
#include "observer/upkeyobserver.h"
#include "observer/leftkeyobserver.h"
#include "observer/rightkeyobserver.h"

class Snake : public Element
{
public:

    QPainterPath shape() const;

    void addToTheScene();
    void removeFromTheScene();
    void run(int step);

    static Snake *getInstance() {
        if(!snake) snake = new Snake();
        return snake;
    }

    void increaseGrowing();
    QPointF getHead();

    //Observer Design Pattern Methods
    void notifyObservers(QKeyEvent *e);
    void installObserver(Observer *o);
    void uninstallObserver(Observer *o);
    void uninstallObserver(int index);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

private:
    static Snake *snake;
    Snake();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int step);

    void handleCollisions();
    void move();

    QList<Observer *> observers;
    QKeyEvent *lastKey;

    QPointF        head;
    int            growing;
    int            speed;
    QList<QPointF> tail;
    int            tickCounter;
};

#endif // SNAKE_H
