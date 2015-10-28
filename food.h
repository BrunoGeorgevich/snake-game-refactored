#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>

class Food : public QGraphicsItem
{
public:

    static Food *getInstance() {
        if(!food) food = new Food(0,-50);
        return food;
    }

    void setPosition(qreal x, qreal y);

private:
    static Food *food;
    Food(qreal x, qreal y);
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QPainterPath shape() const;
};

#endif // FOOD_H
