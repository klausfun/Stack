#include "../include/testSystem.hpp"
#include "../include/Stack.hpp"

template<typename T>
bool test_copy_constructor()
{
    Stack<T> stack;
    if constexpr (std::is_same_v<T, int>)
    {
        stack.push(1);
        stack.push(2);
        stack.push(3);
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        stack.push(1.5);
        stack.push(-2.3);
        stack.push(3.23);
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        stack.push("1");
        stack.push("2");
        stack.push("3");
    }

    Stack<T> copied_stack(stack);

    if (stack.size() != copied_stack.size())
    {
        return false;
    }

    while (!stack.empty())
    {
        if (stack.top() != copied_stack.top())
        {
            std::cout << "FATALITY2: " << stack.top() << " vs " << copied_stack.top() << std::endl;
            return false;
        }
        stack.pop();
        copied_stack.pop();
    }

    return true;
}

template<typename T>
bool test_move_constructor()
{
    Stack<T> stack;
    if constexpr (std::is_same_v<T, int>)
    {
        stack.push(1);
        stack.push(2);
        stack.push(3);
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        stack.push(1.5);
        stack.push(-2.3);
        stack.push(3.23);
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        stack.push("1");
        stack.push("2");
        stack.push("3");
    }

    Stack<T> copied_stack(stack);
    Stack<T> moved_stack(std::move(stack));

    if (stack.size() != 0)
    {
        return false;
    }

    while (!moved_stack.empty())
    {
        if (moved_stack.top() != copied_stack.top())
        {
            return false;
        }
        moved_stack.pop();
        copied_stack.pop();
    }

    return true;
}

template<typename T>
bool test_copy_assignment()
{
    Stack<T> stack;
    if constexpr (std::is_same_v<T, int>)
    {
        stack.push(1);
        stack.push(2);
        stack.push(3);
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        stack.push(1.5);
        stack.push(-2.3);
        stack.push(3.23);
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        stack.push("1");
        stack.push("2");
        stack.push("3");
    }

    Stack<T> assigned_stack;
    assigned_stack = stack;

    if (stack.size() != assigned_stack.size())
    {
        return false;
    }

    while (!stack.empty())
    {
        if (stack.top() != assigned_stack.top())
        {
            return false;
        }
        stack.pop();
        assigned_stack.pop();
    }

    return true;
}

template<typename T>
bool test_move_assignment()
{
    Stack<T> stack;
    if constexpr (std::is_same_v<T, int>)
    {
        stack.push(1);
        stack.push(2);
        stack.push(3);
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        stack.push(1.5);
        stack.push(-2.3);
        stack.push(3.23);
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        stack.push("1");
        stack.push("2");
        stack.push("3");
    }

    Stack<T> copied_stack(stack);
    Stack<T> moved_stack;
    moved_stack = std::move(stack);

    if (stack.size() != 0)
    {
        return false;
    }

    if (moved_stack.size() == 0)
    {
        return false;
    }

    while (!moved_stack.empty())
    {
        if (copied_stack.top() != moved_stack.top())
        {
            return false;
        }
        copied_stack.pop();
        moved_stack.pop();
    }

    return true;
}

template<typename T>
bool test_top()
{
    Stack<T> stack;
    T value;
    if constexpr (std::is_same_v<T, int>)
    {
        value = 42;
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        value = 13.91;
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        value = "72.32";
    }

    stack.push(value);

    return stack.top() == value;
}

template<typename T>
bool test_push()
{
    Stack<T> stack;
    T value;
    if constexpr (std::is_same_v<T, int>)
    {
        value = 42;
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        value = 13.91;
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        value = "72.32";
    }

    stack.push(value);

    return stack.top() == value;
}

template<typename T>
bool test_push2()
{
    Stack<T> stack;
    T value;
    if constexpr (std::is_same_v<T, int>)
    {
        value = 42;
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        value = 42;
    }

    stack.push(42);

    return stack.top() == value;
}

template<typename T>
bool test_pop()
{
    Stack<T> stack;
    T value;
    if constexpr (std::is_same_v<T, int>)
    {
        value = 42;
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        value = 13.91;
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        value = "72.32";
    }

    stack.push(value);

    stack.pop();

    return stack.empty();
}
