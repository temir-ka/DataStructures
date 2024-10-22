#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <stdexcept>
#include <iostream>

template<typename T>
class DoublyList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

public:
    DoublyList();
    ~DoublyList();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    bool isEmpty() const;
    void clear();
    void print() const;
};

template<typename T>
DoublyList<T>::DoublyList() : head(nullptr), tail(nullptr) {}

template<typename T>
DoublyList<T>::~DoublyList() {
    clear();
}

template<typename T>
void DoublyList<T>::push_back(const T& value) {
    Node* newNode = new Node{value, nullptr, tail};
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

template<typename T>
void DoublyList<T>::push_front(const T& value) {
    Node* newNode = new Node{value, head, nullptr};
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

template<typename T>
void DoublyList<T>::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

template<typename T>
void DoublyList<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

template<typename T>
bool DoublyList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void DoublyList<T>::clear() {
    while (!isEmpty()) {
        pop_front();
    }
}

template<typename T>
void DoublyList<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // DOUBLY_LIST_H
