#include <QPainter>

#include "constants.h"
#include "food.h"

static const qreal FOOD_RADIUS = 3;
Food *Food::food = new Food(0,-50);

void Food::setPosition(qreal x, qreal y)
{
    installState(new FoodWaitingState());
    setPos(x, y);
    setData(GD_Type, GO_Food);
}

void Food::addToTheScene()
{
    int x, y;
    x = (int) (qrand() % 100) / 10;
    y = (int) (qrand() % 100) / 10;

    x *= 10;
    y *= 10;

    setPosition(x,y);
    _scene->addItem(this);
}

void Food::removeFromTheScene()
{
    if(!_scene) _scene = scene();
    _scene->removeItem(this);
    addToTheScene();
}

void Food::advance(int phase)
{
    if(collidingItems().size()) {
        installState(new EatedState());
    }

    state->run();
}

Food::Food(qreal x, qreal y)
{
    setPosition(x,y);
}

QRectF Food::boundingRect() const
{
    return QRectF(-TILE_SIZE,    -TILE_SIZE,
                  TILE_SIZE * 2, TILE_SIZE * 2 );
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}

QPainterPath Food::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}
