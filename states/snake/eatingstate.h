#ifndef EATINGSTATE_H
#define EATINGSTATE_H

#include "states/state.h"

class EatingState : public State
{
public:
    EatingState();
    void run();
};

#endif // EATINGSTATE_H
