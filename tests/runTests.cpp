#include <iostream>
#include "testSystem.hpp"
#include "test.cpp"

int main(void)
{
    std::cout << "Testing Vector<double>:\n";
    TestSystem::run_test("double_push", test_push<double>);
    TestSystem::run_test("double_top", test_top<double>);
    TestSystem::run_test("double_pop", test_pop<double>);
    TestSystem::run_test("double_copy_constructor", test_copy_constructor<double>);
    TestSystem::run_test("double_move_constructor", test_move_constructor<double>);
    TestSystem::run_test("double_copy_assignment", test_copy_assignment<double>);
    TestSystem::run_test("double_move_assignment", test_move_assignment<double>);
    printf("\n");

    std::cout << "Testing Vector<int>:\n";
    TestSystem::run_test("int_push", test_push<int>);
    TestSystem::run_test("int_top", test_top<int>);
    TestSystem::run_test("int_pop", test_pop<int>);
    TestSystem::run_test("int_copy_constructor", test_copy_constructor<int>);
    TestSystem::run_test("int_move_constructor", test_move_constructor<int>);
    TestSystem::run_test("int_copy_assignment", test_copy_assignment<int>);
    TestSystem::run_test("int_move_assignment", test_move_assignment<int>);
    printf("\n");

    std::cout << "Testing Vector<std::string>:\n";
    TestSystem::run_test("std::string_push", test_push<std::string>);
    TestSystem::run_test("std::string_top", test_top<std::string>);
    TestSystem::run_test("std::string_pop", test_pop<std::string>);
    TestSystem::run_test("std::string_copy_constructor", test_copy_constructor<std::string>);
    TestSystem::run_test("std::string_move_constructor", test_move_constructor<std::string>);
    TestSystem::run_test("std::string_copy_assignment", test_copy_assignment<std::string>);
    TestSystem::run_test("std::string_move_assignment", test_move_assignment<std::string>);
    printf("\n");

    return 0;
}