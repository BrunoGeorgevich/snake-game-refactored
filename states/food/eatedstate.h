#ifndef EATEDSTATE_H
#define EATEDSTATE_H

#include <QDebug>

#include "states/state.h"

class EatedState : public State
{
public:
    EatedState();
    void run();
};

#endif // EATEDSTATE_H
