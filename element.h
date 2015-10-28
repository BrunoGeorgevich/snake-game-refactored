#ifndef ELEMENT
#define ELEMENT

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>

#include "states/state.h"
#include "observer/observer.h"

class Element : public QGraphicsItem
{
public:
    virtual void addToTheScene() = 0;
    virtual void removeFromTheScene() = 0;

    void installObserver(Observer *ob) {
        observer = ob;
    }

    void installState(State *st) {
        state = st;
    }

protected:
    Observer *observer;
    State *state;
    QGraphicsScene *_scene;
};

#endif // ELEMENT

