#ifndef MAP_H
#define MAP_H

#include <stdexcept>

template<typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;
    };

    Node* root;

    void insert(Node*& node, const K& key, const V& value);
    bool contains(Node* node, const K& key) const;
    V get(Node* node, const K& key) const;
    void clear(Node* node);

public:
    Map();
    ~Map();

    void insert(const K& key, const V& value);
    bool contains(const K& key) const;
    V get(const K& key) const;
    bool isEmpty() const;
};

template<typename K, typename V>
Map<K, V>::Map() : root(nullptr) {}

template<typename K, typename V>
Map<K, V>::~Map() {
    clear(root);
}

template<typename K, typename V>
void Map<K, V>::insert(const K& key, const V& value) {
    insert(root, key, value);
}

template<typename K, typename V>
void Map<K, V>::insert(Node*& node, const K& key, const V& value) {
    if (node == nullptr) {
        node = new Node{key, value, nullptr, nullptr};
    } else if (key < node->key) {
        insert(node->left, key, value);
    } else if (key > node->key) {
        insert(node->right, key, value);
    } else {
        node->value = value;
    }
}

template<typename K, typename V>
bool Map<K, V>::contains(const K& key) const {
    return contains(root, key);
}

template<typename K, typename V>
bool Map<K, V>::contains(Node* node, const K& key) const {
    if (node == nullptr) {
        return false;
    } else if (key < node->key) {
        return contains(node->left, key);
    } else if (key > node->key) {
        return contains(node->right, key);
    } else {
        return true;
    }
}

template<typename K, typename V>
V Map<K, V>::get(const K& key) const {
    return get(root, key);
}

template<typename K, typename V>
V Map<K, V>::get(Node* node, const K& key) const {
    if (node == nullptr) {
        throw std::out_of_range("Key not found");
    } else if (key < node->key) {
        return get(node->left, key);
    } else if (key > node->key) {
        return get(node->right, key);
    } else {
        return node->value;
    }
}

template<typename K, typename V>
void Map<K, V>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename K, typename V>
bool Map<K, V>::isEmpty() const {
    return root == nullptr;
}

#endif // MAP_H
