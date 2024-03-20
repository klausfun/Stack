#include <iostream>

class Logger {
public:
    Logger() { std::cout << "Default constructor called\n\n"; }
    Logger(const Logger&) { std::cout << "Copy constructor called\n\n"; }
    Logger(Logger&&) noexcept { std::cout << "Move constructor called\n\n"; }
    Logger& operator=(const Logger&) {
        std::cout << "Copy assignment called\n\n";
        return *this;
    }
    Logger& operator=(Logger&&) noexcept {
        std::cout << "Move assignment called\n\n";
        return *this;
    }
    ~Logger() { std::cout << "Destructor called\n\n"; }
};

