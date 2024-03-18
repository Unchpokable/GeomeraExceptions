#pragma once
#include <cpptrace/cpptrace.hpp>
#include <type_traits>
#include <sstream>

#define GEOMERA_NO_RETURN [[noreturn]]

namespace GeomeraException
{
    using GeomeraLogicalException = cpptrace::logic_error;
    using GeomeraRuntimeException = cpptrace::runtime_error;
    using GeomeraArgumentException = cpptrace::invalid_argument;

    template<typename Exception = GeomeraLogicalException, std::enable_if_t<std::is_base_of_v<cpptrace::exception_with_message, Exception>, bool> = true>
    GEOMERA_NO_RETURN void Throw(const std::string& message, const char* file, const char* func, int line)
    {
        std::stringstream ss {}; 
        ss << message << "\n"; 
        ss << "function: " << func << ", "; 
        ss << "line: " << line << ", " << "file: " << file << "\n"; 
        std::string errorMessage = ss.str(); 
        throw GeomeraLogicalException(std::move(errorMessage));
    }
}
