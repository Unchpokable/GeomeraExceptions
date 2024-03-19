#include <iostream>
#include <cpptrace/cpptrace.hpp>
#include <Windows.h>

#define USE_VCPP_EXTENSIONS
#include "AssertCall.h"

void Foo(int x)
{
    try
    {
        GEOMERA_THROW_LOGIC("Чё за херня");
    }

    catch (GeomeraException::GeomeraArgumentException& ex)
    {
        std::cout << "Argument" << "\n";
        ex.trace().print();
    }

    catch (GeomeraException::GeomeraLogicalException& ex) 
    {
        std::cout << "Logic" << "\n";
        ex.trace().print();
    }

    catch (GeomeraException::GeomeraRuntimeException& ex) {
        std::cout << "Runtime" << "\n";
        ex.trace().print();
    }
}

int main()
{
    int x = 50;
    Foo(x);
}
