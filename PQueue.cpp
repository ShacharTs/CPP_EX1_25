#include "PQueue.hpp"

PQueue::PQueue(int capacity) : capacity(capacity), size(0) {
    array = new Node*[capacity];
}

bool PQueue::isEmpty() const {
    return size == 0;
}

bool PQueue::isFull() const {
    return size == capacity;
}

void PQueue::enqueue(const int source, const int dest, const int weight) {
    if (isFull()) {
        return;
    }

    Node* newElement = new Node(source, dest, weight);
    int i = size - 1;
    // Insert the new element in sorted order
    while (i >= 0 && array[i]->weight > weight) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = newElement;
    size++;
}

void PQueue::enqueue(int node, int priority) {
    if (isFull()) {
        return;
    }

    Node* newElement = new Node(-1, node, priority);
    int i = size - 1;
    while (i >= 0 && array[i]->weight > priority) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = newElement;
    size++;
}

Node* PQueue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    int minIndex = 0;
    for (int i = 0; i < size; i++) {
        if (array[i]->weight < array[minIndex]->weight) {
            minIndex = i;
        }
    }
    Node* element = array[minIndex];
    // move elements left
    for (int i = minIndex; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    return element;
}

Node* PQueue::peek() const {
    if (isEmpty()) {
        return nullptr;
    }
    return array[0];
}

int PQueue::getDest(const Node* element) const {
    return element->dest;
}

int PQueue::getWeight(const Node* element) const {
    return element->weight;
}

PQueue::~PQueue() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}
