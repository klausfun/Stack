#include <iostream>
#include "Stack.hpp"
#include "Logger.cpp"

int main() {
    Logger logger;
    Stack<Logger> stack;

    std::cout << "Calling push:\n";
    Logger push_logger;
    stack.push(push_logger);

    std::cout << "Calling pop:\n";
    try {
        stack.pop();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

//    std::cout << "Calling top:\n";
//    try {
//        Logger& top_logger = stack.top();
//        std::cout << "Stack top: " << top_logger << '\n';
//    } catch (const std::exception& e) {
//        std::cerr << "Exception caught: " << e.what() << '\n';
//    }

    std::cout << "Calling size:\n";
    std::size_t size = stack.size();
    std::cout << "Stack size: " << size << '\n';

    std::cout << "Calling empty:\n";
    bool is_empty = stack.empty();
    if (is_empty) {
        std::cout << "Stack is empty\n";
    } else {
        std::cout << "Stack is not empty\n";
    }

    return 0;
}