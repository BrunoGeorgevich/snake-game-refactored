#ifndef MOVINGSTATE_H
#define MOVINGSTATE_H

#include "states/state.h"

class MovingState : public State
{
public:
    MovingState();
    void run();
};

#endif // MOVINGSTATE_H
