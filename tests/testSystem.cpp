#include "testSystem.hpp"

namespace TestSystem
{
    TestResult run_test(const char* name, std::function<bool()> test)
    {
        std::cout << name << ": ";
        try
        {
            if (test())
            {
                std::cout << "[OK]" << std::endl;
                return TestResult::OK;
            }
            else
            {
                std::cout << "[FAIL]" << std::endl;
                return TestResult::FAIL;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "[EXCEPTION]" << e.what() << std::endl;
            return TestResult::EXCEPTION;
        }
        catch (...)
        {
            std::cerr << "[ERROR]" << std::endl;
            return TestResult::ERROR;
        }
    }
}