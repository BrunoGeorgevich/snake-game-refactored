#include "downkeyobserver.h"
#include "snake.h"

DownKeyObserver::DownKeyObserver()
{

}

void DownKeyObserver::notify(QKeyEvent *e)
{
    if(e->key() == Qt::Key_S) {
        Snake::getInstance()->moveDown();
    }
}

