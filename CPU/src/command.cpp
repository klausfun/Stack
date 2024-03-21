#include "../include/command.hpp"
#include <iostream>

void CommandBegin::execute(Stack<int>& stack, int& ip) const {
    std::cout << "BEGIN: Перевод процессора в режим исполнения команд." << '\n';
}

void CommandEnd::execute(Stack<int>& stack, int& ip) const {
    std::cout << "END: Остановка выполнения команд." << '\n';
}

CommandPush::CommandPush(Val_t val) : val_(val) {}

void CommandPush::execute(Stack<int>& stack, int& ip) const {
    stack.push(val_);
    std::cout << "PUSH " << val_ << ": Добавление на вершину стека числа " << val_ << '\n';
}

void CommandPop::execute(Stack<int>& stack, int& ip) const {
    if (stack.empty()) {
        throw std::runtime_error("POP: Stack is empty");
    }
    stack.pop();
    std::cout << "POP: Удаление числа из вершины стека" << '\n';
}

CommandPushr::CommandPushr(Reg_t reg) : reg_(reg) {}

void CommandPushr::execute(Stack<int>& stack, int& ip) const {
    // Здесь должен быть код чтения значения из регистра и его добавления на вершину стека
    std::cout << "PUSHR " << get_register_name(reg_) << ": Чтение регистра " << get_register_name(reg_) << " и добавление его на вершину стека" << '\n';
}

CommandPopr::CommandPopr(Reg_t reg) : reg_(reg) {}

void CommandPopr::execute(Stack<int>& stack, int& ip) const {
    if (stack.empty()) {
        throw std::runtime_error("POPR: Stack is empty");
    }
    int value = stack.top();
    stack.pop();
    // Здесь должен быть код записи значения в регистр
    std::cout << "POPR " << get_register_name(reg_) << ": Удаление числа из вершины стека и его запись в регистр " << get_register_name(reg_) << '\n';
}

void CommandAdd::execute(Stack<int>& stack, int& ip) const {
    if (stack.size() < 2) {
        throw std::runtime_error("ADD: Stack has less than 2 elements");
    }
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    stack.push(a + b);
    std::cout << "ADD: Сложение двух верхних значений из стека с сохранением результата на вершине стека" << '\n';
}

void CommandSub::execute(Stack<int>& stack, int& ip) const {
    if (stack.size() < 2) {
        throw std::runtime_error("SUB: Stack has less than 2 elements");
    }
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    stack.push(a - b);
    std::cout << "SUB: Вычитание двух верхних значений из стека с сохранением результата на вершине стека" << '\n';
}

void CommandMul::execute(Stack<int>& stack, int& ip) const {
    if (stack.size() < 2) {
        throw std::runtime_error("MUL: Stack has less than 2 elements");
    }
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    stack.push(a * b);
    std::cout << "MUL: Умножение двух верхних значений из стека с сохранением результата на вершине стека" << '\n';
}

void CommandDiv::execute(Stack<int>& stack, int& ip) const {
    if (stack.size() < 2) {
        throw std::runtime_error("DIV: Stack has less than 2 elements");
    }
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    if (b == 0) {
        throw std::runtime_error("DIV: Division by zero");
    }
    stack.push(a / b);
    std::cout << "DIV: Деление двух верхних значений из стека с сохранением результата на вершине стека" << '\n';
}

void CommandOut::execute(Stack<int>& stack, int& ip) const {
    if (stack.empty()) {
        throw std::runtime_error("OUT: Stack is empty");
    }
    std::cout << "OUT: Удаление числа из вершины стека с выводом в консоль: " << stack.top() << '\n';
    stack.pop();
}

void CommandIn::execute(Stack<int>& stack, int& ip) const {
    int value;
    std::cout << "IN: Введите число для сохранения на вершине стека: ";
    std::cin >> value;
    stack.push(value);
    std::cout << "IN: Считывание из консоли числа " << value << " с сохранением на вершине стека" << '\n';
}