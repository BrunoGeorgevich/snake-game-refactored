#include "leftkeyobserver.h"
#include "snake.h"

LeftKeyObserver::LeftKeyObserver()
{

}

void LeftKeyObserver::notify(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)
        Snake::getInstance()->moveLeft();
}

