#include <iostream>
#include "../include/emulator.hpp"

int main() {
    Emulator emulator("program.txt");
    emulator.run();

    return 0;
}