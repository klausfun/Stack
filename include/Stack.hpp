#pragma once
#include <iostream>
#include <stdexcept>
#include <utility>

template<typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* top_node;

public:
    Stack() = delete;

    Stack(size_t size);

    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;

    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;

    ~Stack();

    void push(const T& value);
    void pop();
    T& top();
    bool empty() const;
};

template<typename T>
Stack<T>::Stack() : top_node(nullptr) {}

template<typename T>
Stack<T>::Stack(const Stack& other) : top_node(nullptr) {
    if (other.top_node) {
        top_node = new Node(other.top_node->data);
        Node* current = top_node;
        Node* other_current = other.top_node->next;
        while (other_current) {
            current->next = new Node(other_current->data);
            current = current->next;
            other_current = other_current->next;
        }
    }
}

template<typename T>
Stack<T>::Stack(Stack&& other) noexcept : top_node(nullptr) {
    std::swap(top_node, other.top_node);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        Stack temp(other);
        std::swap(top_node, temp.top_node);
    }
    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        delete top_node;
        top_node = nullptr;
        std::swap(top_node, other.top_node);
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack() {
    while (top_node) {
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::push(const T& value) {
    Node* new_node = new Node(value);
    new_node->next = top_node;
    top_node = new_node;
}

template<typename T>
void Stack<T>::pop() {
    if (empty())
        throw std::out_of_range("Stack is empty");
    Node* temp = top_node;
    top_node = top_node->next;
    delete temp;
}

template<typename T>
T& Stack<T>::top() {
    if (empty())
        throw std::out_of_range("Stack is empty");
    return top_node->data;
}

template<typename T>
bool Stack<T>::empty() const {
    return top_node == nullptr;
}

// Explicit instantiation for the types used in the program
template class Stack<int>;
template class Stack<double>;
// Add more instantiations as needed for other types