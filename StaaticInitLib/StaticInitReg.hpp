#pragma once

#include "staticinit.h"

template<typename T>
class StaticInitialization
{
public:
    StaticInitialization(StaticInit::Priority priority)
    {
        StaticInit::addInitFunction(T::StaticInit, priority);
    }
};