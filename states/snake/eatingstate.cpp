#include "eatingstate.h"
#include "snake.h"

EatingState::EatingState(){}

void EatingState::run()
{
    Snake::getInstance()->increaseGrowing();
    Snake::getInstance()->installState(new MovingState());
}

