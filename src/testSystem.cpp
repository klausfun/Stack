#include "testSystem.hpp"

namespace TestSystem
{
    TestResult run_test(const char* name, std::function<bool()> test)
    {
        std::cout << "Running test: " << name << std::endl;
        try
        {
            if (test())
            {
                std::cout << "Test passed." << std::endl;
                return TestResult::OK;
            }
            else
            {
                std::cout << "Test failed." << std::endl;
                return TestResult::FAIL;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Test failed with exception: " << e.what() << std::endl;
            return TestResult::EXCEPTION;
        }
        catch (...)
        {
            std::cerr << "Test failed with unknown exception." << std::endl;
            return TestResult::ERROR;
        }
    }
}