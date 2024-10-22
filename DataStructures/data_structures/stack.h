#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* topNode;

public:
    Stack();
    ~Stack();

    void push(const T& value);
    void pop();
    T top() const;
    bool isEmpty() const;
};

template<typename T>
Stack<T>::Stack() : topNode(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

template<typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

template<typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->data;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return topNode == nullptr;
}

#endif // STACK_H
