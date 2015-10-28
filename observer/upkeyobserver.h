#ifndef UPKEYOBSERVER_H
#define UPKEYOBSERVER_H

#include "observer.h"

class UpKeyObserver : public Observer
{
public:
    UpKeyObserver();
    void notify(QKeyEvent *e);
};

#endif // UPKEYOBSERVER_H
