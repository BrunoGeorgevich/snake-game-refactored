#ifndef LEFTKEYOBSERVER_H
#define LEFTKEYOBSERVER_H

#include "observer.h"

class LeftKeyObserver : public Observer
{
public:
    LeftKeyObserver();
    void notify(QKeyEvent *e);
};

#endif // LEFTKEYOBSERVER_H
