#include <iostream>

using namespace std;

class PQueue {
public:
    struct PQElement {
        int source;
        int dest;
        int weight;

        PQElement(int source,int dest, int weight) : source(source), dest(dest), weight(weight) {}
    };

    PQElement** array;
    int size;
    int capacity;

public:
    explicit PQueue(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        array = new PQElement*[capacity];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    // Enqueue with priority (based on edge weight)
    void enqueue(const int source,const int dest, const int weight) {
        if (isFull()) {
            return;
        }

        PQElement* newElement = new PQElement(source,dest, weight);

        // Insert the new element in sorted order by priority (weight)
        int i = size - 1;
        while (i >= 0 && array[i]->weight > weight) {  // In priority queue, smallest weight should come first
            array[i + 1] = array[i];  // Shift the element right
            i--;
        }

        // Insert the new element at the correct position
        array[i + 1] = newElement;
        size++;
    }

    void enqueue(int node, int priority) {
        if (isFull()) {
            return;
        }

        PQElement* newElement = new PQElement(-1, node, priority);

        int i = size - 1;
        while (i >= 0 && array[i]->weight > priority) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = newElement;
        size++;
    }


    // Dequeue the highest priority element (the one with the smallest weight)
    PQElement* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }

        // Find the index of the element with the smallest weight
        int minIndex = 0;
        for (int i = 0; i < size; i++) {
            if (array[i]->weight < array[minIndex]->weight) {
                minIndex = i;
            }
        }

        // Get the element with the smallest weight
        PQElement* element = array[minIndex];

        // Shift all elements to the left to fill the gap
        for (int i = minIndex; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        // Decrease the size of the queue
        size--;

        return element;
    }


    PQElement* peek() const {
        if (isEmpty()) {
            return nullptr;
        }

        return array[0];  // Return the element with the minimum weight
    }


    int getDest(const PQElement* element) const {
        return element->dest;
    }

    int getWeight(const PQElement* element) const {
        return element->weight;
    }

    ~PQueue() {
        for (int i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;  // Delete the array
    }
};
