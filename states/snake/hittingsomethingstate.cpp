#include "hittingsomethingstate.h"
#include "snake.h"

HittingSomethingState::HittingSomethingState(){}

void HittingSomethingState::run()
{
    Snake::getInstance()->removeFromTheScene();
}

