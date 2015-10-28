#ifndef SNAKE_H
#define SNAKE_H

#include "element.h"
#include "states/snake/movingstate.h"
#include "states/snake/eatingstate.h"
#include "states/snake/hittingsomethingstate.h"

class Snake : public Element
{
public:
    enum Direction {
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

    QPainterPath shape() const;
    void setMoveDirection(Direction direction);

    void addToTheScene();
    void removeFromTheScene();
    void run(int step);

    static Snake *getInstance() {
        if(!snake) snake = new Snake();
        return snake;
    }

    void increaseGrowing();

private:
    static Snake *snake;
    Snake();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int step);

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void handleCollisions();

    QPointF        head;
    int            growing;
    int            speed;
    QList<QPointF> tail;
    int            tickCounter;
    Direction      moveDirection;
};

#endif // SNAKE_H
