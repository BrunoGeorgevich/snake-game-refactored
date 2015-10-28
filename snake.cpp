#include <QPainter>

#include "constants.h"
#include "snake.h"

static const qreal SNAKE_SIZE = 10;
Snake *Snake::snake = new Snake();

Snake::Snake() :
    head(0, 0),
    growing(7),
    speed(3)
{
    state = new MovingState();

    installObserver(new DownKeyObserver());
    installObserver(new UpKeyObserver());
    installObserver(new LeftKeyObserver());
    installObserver(new RightKeyObserver());
}

QRectF Snake::boundingRect() const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    foreach (QPointF p, tail) {
        maxX = p.x() > maxX ? p.x() : maxX;
        maxY = p.y() > maxY ? p.y() : maxY;
        minX = p.x() < minX ? p.x() : minX;
        minY = p.y() < minY ? p.y() : minY;
    }

    QPointF tl = mapFromScene(QPointF(minX, minY));
    QPointF br = mapFromScene(QPointF(maxX, maxY));

    QRectF bound = QRectF(tl.x(),  // x
                          tl.y(),  // y
                          br.x() - tl.x() + SNAKE_SIZE,      // width
                          br.y() - tl.y() + SNAKE_SIZE       //height
                          );
    return bound;
}

QPainterPath Snake::shape() const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0, 0, SNAKE_SIZE, SNAKE_SIZE));

    foreach (QPointF p, tail) {
        QPointF itemp = mapFromScene(p);
        path.addRect(QRectF(itemp.x(), itemp.y(), SNAKE_SIZE, SNAKE_SIZE));
    }

    return path;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}

void Snake::addToTheScene()
{
    tail.clear();
    growing = 7;
    speed = 3;
    setPos(0,0);
    head.setX(0);
    head.setY(0);
    _scene->addItem(this);
    lastKey = 0;

    installState(new MovingState());
}

void Snake::removeFromTheScene()
{
    if(!_scene) _scene = scene();
    _scene->removeItem(this);
    addToTheScene();
}

void Snake::run(int step) {
    if(!step)
        return;
    if (tickCounter++ % speed != 0) {
        return;
    }
    if(lastKey)
        notifyObservers(lastKey);
    setPos(head);
}

void Snake::increaseGrowing()
{
    growing += 1;
}

QPointF Snake::getHead()
{
    return head;
}

void Snake::notifyObservers(QKeyEvent *e)
{
    if(lastKey != e && e->key() != 0) {
        lastKey = new QKeyEvent(*e);
    }

    foreach (Observer *o, observers) {
        o->notify(lastKey);
    }
}

void Snake::advance(int step)
{
    run(step);
    state->run();
    handleCollisions();
}

void Snake::installObserver(Observer *o)
{
    observers.append(o);
}

void Snake::uninstallObserver(Observer *o)
{
    observers.removeAll(o);
}

void Snake::uninstallObserver(int index)
{
    observers.removeAt(index);
}

void Snake::move()
{
    if (growing > 0) {
        QPointF tailPoint = head;
        tail << tailPoint;
        growing -= 1;
    } else {
        tail.takeFirst();
        tail << head;
    }
}

void Snake::moveLeft()
{
    move();
    head.rx() -= SNAKE_SIZE;
    if (head.rx() < -100) {
        installState(new HittingSomethingState());
    }
    setPos(head);
}

void Snake::moveRight()
{
    move();
    head.rx() += SNAKE_SIZE;
    if (head.rx() > 100) {
        installState(new HittingSomethingState());
    }
    setPos(head);
}

void Snake::moveUp()
{
    move();
    head.ry() -= SNAKE_SIZE;
    if (head.ry() < -100) {
        installState(new HittingSomethingState());
    }
    setPos(head);
}

void Snake::moveDown()
{
    move();
    head.ry() += SNAKE_SIZE;
    if (head.ry() > 100) {
        installState(new HittingSomethingState());
    }
    setPos(head);
}

void Snake::handleCollisions()
{
    QList<QGraphicsItem *> collisions = collidingItems();

    // Check collisions with other objects on screen
    foreach (QGraphicsItem *collidingItem, collisions)
        if (collidingItem->data(GD_Type) == GO_Food)
            installState(new EatingState());

    if (tail.contains(head)) {
        Snake::getInstance()->installState(new HittingSomethingState());
    }
}
