#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

    void resize();

public:
    Vector();
    ~Vector();

    void push_back(const T& value);
    void pop_back();
    int get_size() const;
    T& operator[](int index);
};

template<typename T>
Vector<T>::Vector() : size(0), capacity(1) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
void Vector<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        size--;
    } else {
        throw std::out_of_range("Vector is empty");
    }
}

template<typename T>
int Vector<T>::get_size() const {
    return size;
}

template<typename T>
T& Vector<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of bounds");
    }
}

#endif // VECTOR_H
