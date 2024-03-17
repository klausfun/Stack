#pragma once
#include <iostream>
#include <functional>
#include <stdexcept>

namespace TestSystem
{
    enum TestResult
    {
        FAIL,
        OK,
        EXCEPTION,
        ERROR
    };

    TestResult run_test(const char* name, std::function<bool()> test);
}