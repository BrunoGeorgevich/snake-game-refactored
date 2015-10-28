#include "rightkeyobserver.h"
#include "snake.h"

RightKeyObserver::RightKeyObserver()
{

}

void RightKeyObserver::notify(QKeyEvent *e)
{
    if(e->key() == Qt::Key_D)
        Snake::getInstance()->moveRight();
}

