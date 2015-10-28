#include "eatedstate.h"
#include "food.h"

EatedState::EatedState()
{

}

void EatedState::run()
{
    qDebug() << "FOOD WAS EATED!";
    Food::getInstance()->removeFromTheScene();
}

