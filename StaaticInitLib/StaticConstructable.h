#pragma once
#include "staticinit.h"
#include <iostream>

template<typename T>
class StaticConstructable
{
public:
    StaticConstructable(StaticInit::Priority priority)
    {
        StaticInit::addInitFunction([this]() { this->StaticInit(); }, priority);
    }

    virtual ~StaticConstructable() = default;

    virtual void StaticInit()
    {
        std::cout << "base static init called!\n";
    }
};

