#include "eatedstate.h"
#include "food.h"

EatedState::EatedState()
{

}

void EatedState::run()
{
    Food::getInstance()->removeFromTheScene();
}

