#include "../include/Logger.hpp"
#include "../include/Stack.hpp"

Logger::Logger(Logger&& other) noexcept
{
    printf("move constructor");
}

Logger::Logger(const Logger& other) noexcept
{
printf("copy constructor");
}

Logger::Logger() noexcept
{
    printf("default constructor");
}

Logger& Logger::operator=(const Logger& other)
{
    printf("copy assignment");
}

Logger& Logger::operator=(Logger&& other)
{
    printf("move assignment");
}

Logger::~Logger()
{
    printf("destructor");

}