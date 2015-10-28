#ifndef DOWNKEYOBSERVER_H
#define DOWNKEYOBSERVER_H

#include "observer.h"

class DownKeyObserver : public Observer
{
public:
    DownKeyObserver();
    void notify(QKeyEvent *e);
};

#endif // DOWNKEYOBSERVER_H
