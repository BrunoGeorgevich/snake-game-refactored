#include "upkeyobserver.h"
#include "snake.h"

UpKeyObserver::UpKeyObserver(){}

void UpKeyObserver::notify(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W)
        Snake::getInstance()->moveUp();
}

