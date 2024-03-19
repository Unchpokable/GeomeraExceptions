#pragma once
#include <cpptrace/cpptrace.hpp>
#include <type_traits>
#include <sstream>

#define NO_RETURN [[noreturn]]

constexpr std::size_t SkipThrowCallersFrames = 3;

namespace Exception
{
    class TracedException : public cpptrace::exception_with_message 
    {
    public:
        explicit TracedException(std::string&& message_arg, std::size_t skip = 1) noexcept
            : exception_with_message(std::move(message_arg), skip)
        {}
        
        const char* what() const noexcept override 
        {
            return message();
        }
    };

    class LogicalException : public TracedException 
    {
    public:
        explicit LogicalException(std::string&& message, std::size_t skip = 1) noexcept
            : TracedException(std::move(message), skip) {}
    };
    
    class RuntimeException : public TracedException 
    {
    public:
        explicit RuntimeException(std::string&& message, std::size_t skip = 1) noexcept
            : TracedException(std::move(message), skip) {}
    };

    class ArgumentException : public TracedException
    {
    public:
        explicit ArgumentException(std::string&& message, std::size_t skip = 1) noexcept
            : TracedException(std::move(message), skip) {}
    };

    template<typename Exception = LogicalException, std::enable_if_t<std::is_base_of_v<TracedException, Exception>, bool> = true>
    NO_RETURN void Throw(const std::string& message, const char* file, const char* func, int line)
    {
        std::stringstream ss {};
        ss << message << "\n";
        ss << "function: " << func << ", "; 
        ss << "line: " << line << ", " << "file: " << file << "\n";
        std::string errorMessage = ss.str();

        throw Exception(std::move(errorMessage), SkipThrowCallersFrames); // skip this call stack frame
    }
}