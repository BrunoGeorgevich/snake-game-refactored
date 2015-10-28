#include "eatingstate.h"
#include "snake.h"

EatingState::EatingState(){}

void EatingState::run()
{
    qDebug() << "SNAKE IS EATING!";
    Snake::getInstance()->increaseGrowing();
    Snake::getInstance()->installState(new MovingState());
}

