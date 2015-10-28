#ifndef FOOD_H
#define FOOD_H

#include "element.h"

#include "states/food/foodwaitingstate.h"
#include "states/food/eatedstate.h"

class Food : public Element
{
public:

    static Food *getInstance() {
        if(!food) food = new Food(0,-50);
        return food;
    }

    void setPosition(qreal x, qreal y);
    void addToTheScene();
    void removeFromTheScene();

    void advance(int phase);

private:
    static Food *food;
    Food(qreal x, qreal y);
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QPainterPath shape() const;
    QGraphicsScene *_scene;
};

#endif // FOOD_H
