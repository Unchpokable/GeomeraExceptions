#include <iostream>

#include "staticinit.h"
#include "StaticInitReg.hpp"
#include "macro.h"
#include "StaticConstructable.h"
#include "staticinit.h"

void Foo()
{
    std::cout << "Hey man!";
}

class TestA
{
public:
    STATIC_CONSTRUCTOR(TestA, StaticInit::Priority::Normal)
};

class TestB
{
public:
    STATIC_CONSTRUCTOR(TestB, StaticInit::Priority::High)
};

STATIC_CONSTRUCTOR_IMPL(TestB)
{
    std::cout << "Static Init TestB With Macro and High priority\n";
}

STATIC_CONSTRUCTOR_IMPL(TestA)
{
    std::cout << "Static init TestA With Macro and low priority\n";
}

class TestC : StaticConstructable<TestC>
{
public:
    TestC() : StaticConstructable(StaticInit::Priority::High)
    {
    }

    void StaticInit() override
    {
        std::cout << "TestC overriden staticInit test with High priority\n";
    }
};

int main()
{
    std::cout << "Main called\n";
    TestC c {};
    StaticInit::execute();
    std::cout << "End main\n";
}