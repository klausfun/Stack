#pragma once
#include "Stack.hpp"
#include "Command.hpp"
#include <vector>

class CPU {
public:
    CPU(Stack<int>& stack);

    void load_program(std::vector<Command*>& program);
    void execute();

private:
    Stack<int>& stack_;
    std::vector<Command*> program_;
    int ip_;  // Instruction Pointer
};