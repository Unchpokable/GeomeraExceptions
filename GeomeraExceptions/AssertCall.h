#pragma once
#include "Assert.hpp"
#include <string>
#include <sstream>

#ifdef USE_VCPP_EXTENSIONS
#define FUNCNAME __FUNCSIG__
#else
#define FUNCNAME __FUNCTION__
#endif

#define GEOMERA_THROW_EXCEPTION(exception, message) ::GeomeraException::Throw<exception>(message, __FILE__, FUNCNAME, __LINE__)

#define ASSERT_LOGIC(condition) \
    if (!(condition)) \
    { \
        GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraLogicalException, ::std::string("Logical Error: ") +  #condition + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_LOGIC_MESSAGE(condition, message) \
    if (!(condition)) \
    { \
        GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraLogicalException, ::std::string("Logical Error: ") +  #condition + ", " + (message) + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_ARGUMENT(condition) \
    if (!(condition)) \
    { \
        GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraArgumentException, ::std::string("Invalid Argument: ") + #condition + "\n"); \
    } \
    else \
    { \
        (void)0; \
    }

#define ASSERT_ARGUMENT_MESSAGE(condition, message) \
if (!(condition)) \
    { \
        GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraArgumentException, ::std::string("Invalid Argument: ") +  #condition + ", " + (message) + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_RUNTIME(condition) \
    if (!(condition)) \
    { \
        GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraRuntimeException, ::std::string("Runtime Error: ") + #condition + "\n"); \
    } \
    else \
    { \
        (void)0; \
    }

#define ASSERT_RUNTIME_MESSAGE(condition, message) \
if (!(condition)) \
    { \
        GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraRuntimeException, ::std::string("Runtime Error: ") +  #condition + ", " + (message) + "\n"); \
    } \
    else \
    { \
        (void)0 ; \
    }

#define ASSERT_NOT_NULL(parameter, exception) \
    if ((parameter) == nullptr) GEOMERA_THROW_EXCEPTION(exception, ::std::string(#parameter) + " is nullptr"); else (void)0;

#define ASSERT_NOT_NULL_LOGIC(parameter) ASSERT_NOT_NULL(parameter, ::GeomeraException::GeomeraLogicalException)

#define ASSERT_NOT_NULL_ARGUMENT(parameter) ASSERT_NOT_NULL(parameter, ::GeomeraException::GeomeraArgumentException)

#define ASSERT_NOT_NULL_RUNTIME(parameter) ASSERT_NOT_NULL(parameter, ::GeomeraException::GeomeraRuntimeException)

#define GEOMERA_THROW_LOGIC(message) GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraLogicalException, message)

#define GEOMERA_THROW_ARGUMENT(message) GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraArgumentException, message)

#define GEOMERA_THROW_RUNTIME(message) GEOMERA_THROW_EXCEPTION(::GeomeraException::GeomeraRUNTIMEException, message)