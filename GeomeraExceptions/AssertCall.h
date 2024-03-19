#pragma once
#include "Assert.hpp"
#include <string>
#include <sstream>

#ifdef _MSC_VER
#define FUNCNAME __FUNCSIG__
#elif defined (__GNUC__)
#define FUNCNAME __PRETTY_FUNCTION__
#else
#define FUNCNAME __FUNCTION__
#endif

#define THROW_EXCEPTION(exception, message) ::Exception::Throw<exception>(message, __FILE__, FUNCNAME, __LINE__)

#define ASSERT_LOGIC(condition) \
    if (!(condition)) \
    { \
        THROW_EXCEPTION(::Exception::LogicalException, ::std::string("Logical Error: ") +  #condition + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_LOGIC_MESSAGE(condition, message) \
    if (!(condition)) \
    { \
        THROW_EXCEPTION(::Exception::LogicalException, ::std::string("Logical Error: ") +  #condition + ", " + (message) + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_ARGUMENT(condition) \
    if (!(condition)) \
    { \
        THROW_EXCEPTION(::Exception::ArgumentException, ::std::string("Invalid Argument: ") + #condition + "\n"); \
    } \
    else \
    { \
        (void)0; \
    }

#define ASSERT_ARGUMENT_MESSAGE(condition, message) \
if (!(condition)) \
    { \
        THROW_EXCEPTION(::Exception::ArgumentException, ::std::string("Invalid Argument: ") +  #condition + ", " + (message) + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_RUNTIME(condition) \
    if (!(condition)) \
    { \
        THROW_EXCEPTION(::Exception::RuntimeException, ::std::string("Runtime Error: ") + #condition + "\n"); \
    } \
    else \
    { \
        (void)0; \
    }

#define ASSERT_RUNTIME_MESSAGE(condition, message) \
if (!(condition)) \
    { \
        THROW_EXCEPTION(::Exception::RuntimeException, ::std::string("Runtime Error: ") +  #condition + ", " + (message) + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_NOT_NULL(parameter, exception) \
    if ((parameter) == nullptr) THROW_EXCEPTION(exception, ::std::string(#parameter) + " is nullptr"); else (void)0;

#define ASSERT_NOT_NULL_LOGIC(parameter) ASSERT_NOT_NULL(parameter, ::Exception::LogicalException)

#define ASSERT_NOT_NULL_ARGUMENT(parameter) ASSERT_NOT_NULL(parameter, ::Exception::ArgumentException)

#define ASSERT_NOT_NULL_RUNTIME(parameter) ASSERT_NOT_NULL(parameter, ::Exception::RuntimeException)

#define THROW_LOGIC(message) THROW_EXCEPTION(::Exception::LogicalException, message)

#define THROW_ARGUMENT(message) THROW_EXCEPTION(::Exception::ArgumentException, message)

#define THROW_RUNTIME(message) THROW_EXCEPTION(::Exception::RuntimeException, message)
