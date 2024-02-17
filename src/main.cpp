#include <iostream>
#include "../include/Stack.hpp"
#include <cassert>

int main()
{
    // Тест конструктора по умолчанию и метода empty()
    Stack<int> stack;
    assert(stack.empty()); // Ожидаем, что стек пустой

    // Тест методов push(), top() и empty()
    stack.push(42);
    assert(!stack.empty()); // Ожидаем, что стек не пустой
    assert(stack.top() == 42); // Ожидаем, что вершина стека содержит 42

    // Тест метода pop()
    stack.pop();
    assert(stack.empty()); // Ожидаем, что стек снова пустой

    // Тест на добавление и извлечение нескольких элементов
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.top() == 3); // Ожидаем, что вершина стека содержит 3
    stack.pop();
    assert(stack.top() == 2); // Ожидаем, что вершина стека содержит 2
    stack.pop();
    assert(stack.top() == 1); // Ожидаем, что вершина стека содержит 1
    stack.pop();
    assert(stack.empty()); // Ожидаем, что стек снова пустой

    std::cout << "All tests passed successfully!\n";

    return 0;
}