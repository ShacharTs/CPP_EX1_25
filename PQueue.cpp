#include "PQueue.hpp"

#include <stdexcept>

// using generic class for better uses
template class PQueue<Node>;

// Constructor
template <typename T>
PQueue<T>::PQueue(int capacity) : size(0), capacity(capacity) {
    array = new T*[capacity];
}

template <typename T>
bool PQueue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
bool PQueue<T>::isFull() const {
    return size == capacity;
}

template <typename T>
void PQueue<T>::enqueue(const int source, const int dest, const int weight) {
    if (isFull()) {
        throw std::overflow_error("Queue is full");
    }
    T* newElement = new T(source, dest, weight);
    int i = size;
    while (i > 0 && array[i - 1]->weight > weight) {
        array[i] = array[i - 1];
        i--;
    }
    array[i] = newElement;
    size++;
}


// Temp
// template <typename T>
// void PQueue<T>::enqueue(int node, int priority) {
//     if (isFull()) return;
//     T* newElement = new T(-1, node, priority);
//     int i = size - 1;
//     while (i >= 0 && array[i]->weight > priority) {
//         array[i + 1] = array[i];
//         i--;
//     }
//     array[i + 1] = newElement;
//     size++;
// }

template <typename T>
T* PQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Priority queue is empty. Cannot dequeue element.");
    }
    T* element = array[0];
    for (int i = 1; i < size; i++) {
        array[i - 1] = array[i];
    }
    size--;
    return element;
}

template <typename T>
T* PQueue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Priority queue is empty. Cannot peek element.");
    }
    return array[0];
}

// template <typename T>
// int PQueue<T>::getDest(const T* element) const {
//     return element->dest;
// }
//
// template <typename T>
// int PQueue<T>::getWeight(const T* element) const {
//     return element->weight;
// }

template <typename T>
PQueue<T>::~PQueue() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}



