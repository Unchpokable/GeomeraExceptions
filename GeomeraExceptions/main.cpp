#include <iostream>
#include <cpptrace/cpptrace.hpp>

#define USE_VCPP_EXTENSIONS
#include "AssertCall.h"

void Foo(int x)
{
    try
    {
        ASSERT_LOGIC_MESSAGE(x > 15, "X should be higher than 15")
        GEOMERA_THROW_LOGIC("Logic exception here!")
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    catch (GeomeraException::GeomeraLogicalException& ex) 
    {
        std::cout << ex.what() << "\n";
    }
}

int main()
{
    std::cout << "Hello World!\n";
    int x = 50;
    Foo(x);
}
