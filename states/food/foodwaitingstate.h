#ifndef FOODWAITINGSTATE_H
#define FOODWAITINGSTATE_H

#include "states/state.h"

class FoodWaitingState : public State
{
public:
    FoodWaitingState();
    void run();
};

#endif // FOODWAITINGSTATE_H
