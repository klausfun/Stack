#include <iostream>
#include "testSystem.hpp"
#include "test.cpp" // Включаем определения тестов

int main(void) {
    // Пример запуска тестов
    std::cout << "Testing Vector<double>:\n";
    TestSystem::run_test("double-move-assignment", test_move_assignment<double>);
    // Добавьте другие вызовы run_test для других тестов

    return 0;
}