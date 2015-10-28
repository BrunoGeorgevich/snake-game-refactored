#include "downkeyobserver.h"
#include "snake.h"

DownKeyObserver::DownKeyObserver()
{

}

void DownKeyObserver::notify(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Down) {
        Snake::getInstance()->moveDown();
    }
}

