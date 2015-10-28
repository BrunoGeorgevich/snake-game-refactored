#ifndef OBSERVER_H
#define OBSERVER_H

#include <QKeyEvent>

class Observer
{
public:
    virtual void notify(QKeyEvent *e) = 0;
};

#endif // OBSERVER_H
