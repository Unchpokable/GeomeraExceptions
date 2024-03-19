#include <iostream>
#include <cpptrace/cpptrace.hpp>
#include <Windows.h>

#include "AssertCall.h"

void Nullptr(void* ptr) {
    try {
        ASSERT_NOT_NULL_ARGUMENT(ptr);
    }
    catch (Exception::ArgumentException& ex) {
        std::cout << "Argument null" << "\n";
        std::cout << ex.what() << "\n";
        ex.trace().print();
    }
}

void Foo(int x)
{
    try
    {
        ASSERT_ARGUMENT_MESSAGE(x < 15, "Abobus")
    }

    catch (Exception::ArgumentException& ex)
    {
        std::cout << "Argument" << "\n";
        std::cout << ex.what() << "\n";
        ex.trace().print();
    }

    catch (Exception::LogicalException& ex) 
    {
        std::cout << "Logic" << "\n";
        std::cout << ex.what() << "\n";
        ex.trace().print();
    }

    catch (Exception::RuntimeException& ex)
    {
        std::cout << "Runtime" << "\n";
        std::cout << ex.what() << "\n";
        ex.trace().print();
    }
}

int main()
{
    int x = 50;
    Foo(x);
    Nullptr(nullptr);
}
