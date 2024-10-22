#ifndef SET_H
#define SET_H

#include <stdexcept>

template<typename T>
class Set {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* root;

    void insert(Node*& node, const T& value);
    bool contains(Node* node, const T& value) const;
    void clear(Node* node);

public:
    Set();
    ~Set();

    void insert(const T& value);
    bool contains(const T& value) const;
    bool isEmpty() const;
};

template<typename T>
Set<T>::Set() : root(nullptr) {}

template<typename T>
Set<T>::~Set() {
    clear(root);
}

template<typename T>
void Set<T>::insert(const T& value) {
    insert(root, value);
}

template<typename T>
void Set<T>::insert(Node*& node, const T& value) {
    if (node == nullptr) {
        node = new Node{value, nullptr, nullptr};
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }

}

template<typename T>
bool Set<T>::contains(const T& value) const {
    return contains(root, value);
}

template<typename T>
bool Set<T>::contains(Node* node, const T& value) const {
    if (node == nullptr) {
        return false;
    } else if (value < node->data) {
        return contains(node->left, value);
    } else if (value > node->data) {
        return contains(node->right, value);
    } else {
        return true;
    }
}

template<typename T>
void Set<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename T>
bool Set<T>::isEmpty() const {
    return root == nullptr;
}

#endif // SET_H
