#pragma once
#include <cpptrace/cpptrace.hpp>
#include <type_traits>
#include <sstream>

#define GEOMERA_NO_RETURN [[noreturn]]

constexpr std::size_t SkipThrowCallersFrames = 3;

namespace GeomeraException
{
    class GeomeraTracedException : public cpptrace::exception_with_message 
    {
    public:
        explicit GeomeraTracedException(std::string&& message_arg, std::size_t skip = 1) noexcept
            : exception_with_message(std::move(message_arg), skip)
        {}
        
        const char* what() const noexcept override 
        {
            return message();
        }
    };

    class GeomeraLogicalException : public GeomeraTracedException 
    {
    public:
        explicit GeomeraLogicalException(std::string&& message, std::size_t skip = 1) noexcept
            : GeomeraTracedException(std::move(message), skip) {}
    };
    
    class GeomeraRuntimeException : public GeomeraTracedException 
    {
    public:
        explicit GeomeraRuntimeException(std::string&& message, std::size_t skip = 1) noexcept
            : GeomeraTracedException(std::move(message), skip) {}
    };

    class GeomeraArgumentException : public GeomeraTracedException
    {
    public:
        explicit GeomeraArgumentException(std::string&& message, std::size_t skip = 1) noexcept
            : GeomeraTracedException(std::move(message), skip) {}
    };

    template<typename Exception = GeomeraLogicalException, std::enable_if_t<std::is_base_of_v<GeomeraTracedException, Exception>, bool> = true>
    GEOMERA_NO_RETURN void Throw(const std::string& message, const char* file, const char* func, int line)
    {
        std::stringstream ss {}; 
        ss << message << "\n"; 
        ss << "function: " << func << ", "; 
        ss << "line: " << line << ", " << "file: " << file << "\n";
        std::string errorMessage = ss.str();

        throw Exception(std::move(errorMessage), SkipThrowCallersFrames); // skip this call stack frame
    }
}