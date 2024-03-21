#pragma once
#include <string>

class Emulator {
public:
    Emulator(const std::string& filename);

    void run();

private:
    std::string filename_;
};