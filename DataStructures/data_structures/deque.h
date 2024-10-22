#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>

template<typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    Node* frontNode;
    Node* rearNode;

public:
    Deque();
    ~Deque();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
    bool isEmpty() const;
};

template<typename T>
Deque<T>::Deque() : frontNode(nullptr), rearNode(nullptr) {}

template<typename T>
Deque<T>::~Deque() {
    while (!isEmpty()) {
        pop_front();
    }
}

template<typename T>
void Deque<T>::push_front(const T& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = frontNode;
    newNode->prev = nullptr;

    if (frontNode) {
        frontNode->prev = newNode;
    } else {
        rearNode = newNode;
    }
    frontNode = newNode;
}

template<typename T>
void Deque<T>::push_back(const T& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = rearNode;

    if (rearNode) {
        rearNode->next = newNode;
    } else {
        frontNode = newNode;
    }
    rearNode = newNode;
}

template<typename T>
void Deque<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    if (frontNode) {
        frontNode->prev = nullptr;
    } else {
        rearNode = nullptr;
    }
    delete temp;
}

template<typename T>
void Deque<T>::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    Node* temp = rearNode;
    rearNode = rearNode->prev;
    if (rearNode) {
        rearNode->next = nullptr;
    } else {
        frontNode = nullptr;
    }
    delete temp;
}

template<typename T>
T Deque<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    return frontNode->data;
}

template<typename T>
T Deque<T>::back() const {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    return rearNode->data;
}

template<typename T>
bool Deque<T>::isEmpty() const {
    return frontNode == nullptr;
}

#endif // DEQUE_H
