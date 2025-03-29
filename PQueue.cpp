#include "PQueue.hpp"

PQueue::PQueue(int capacity) :  size(0), capacity(capacity) {
    array = new Node*[capacity];
}

bool PQueue::isEmpty() const {
    return size == 0;
}

bool PQueue::isFull() const {
    return size == capacity;
}

void PQueue::enqueue(int source, int dest, int weight) {
    if (isFull()) return;

    Node* newElement = new Node(source, dest, weight);

    int i = size;
    while (i > 0 && array[i - 1]->weight > weight) {
        array[i] = array[i - 1];
        i--;
    }
    array[i] = newElement;
    size++;
}


void PQueue::enqueue(const int node, const int priority) {
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
    Node* element = array[0];
    // shift all elements to the left
    for (int i = 1; i < size; i++) {
        array[i - 1] = array[i];
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
