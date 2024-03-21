#include "../include/CPU.hpp"

CPU::CPU(Stack<int>& stack) : stack_(stack), ip_(0) {}

void CPU::load_program(std::vector<Command*>& program) {
    program_ = program;
}

void CPU::execute() {
    while (ip_ < program_.size()) {
        program_[ip_]->execute(stack_, ip_);
        ++ip_;
    }
}