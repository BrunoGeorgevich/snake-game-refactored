#ifndef RIGHTKEYOBSERVER_H
#define RIGHTKEYOBSERVER_H

#include "observer.h"

class RightKeyObserver : public Observer
{
public:
    RightKeyObserver();
    void notify(QKeyEvent *e);
};

#endif // RIGHTKEYOBSERVER_H
