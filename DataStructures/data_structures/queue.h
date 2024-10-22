#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* frontNode;
    Node* rearNode;

public:
    Queue();
    ~Queue();

    void enqueue(const T& value);
    void dequeue();
    T front() const;
    bool isEmpty() const;
};

template<typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr) {}

template<typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::enqueue(const T& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (rearNode) {
        rearNode->next = newNode;
    } else {
        frontNode = newNode;
    }
    rearNode = newNode;
}

template<typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    if (!frontNode) {
        rearNode = nullptr;
    }
    delete temp;
}

template<typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return frontNode->data;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

#endif // QUEUE_H
