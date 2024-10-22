#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <iostream>

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    List();
    ~List();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    bool isEmpty() const;
    void clear();
    void print() const;
};

template<typename T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node{value, nullptr};
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

template<typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node{value, head};
    if (!head) {
        tail = newNode;
    }
    head = newNode;
}

template<typename T>
void List<T>::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
}

template<typename T>
void List<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = head;
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
    delete temp;
}

template<typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void List<T>::clear() {
    while (!isEmpty()) {
        pop_front();
    }
}

template<typename T>
void List<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // LIST_H
