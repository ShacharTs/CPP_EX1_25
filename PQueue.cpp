#include <iostream>

using namespace std;

class PQueue {
public:
    struct PQElement {
        int dest;
        int weight;

        PQElement(int dest, int weight) : dest(dest), weight(weight) {}
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
    void enqueue(const int dest, const int weight) {
        if (isFull()) {
            return;
        }

        PQElement* newElement = new PQElement(dest, weight);

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

    // Dequeue the highest priority element (the one with the smallest weight)
    PQElement* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }

        PQElement* element = array[0];  // Get the element with the minimum weight
        // Shift all elements to the left
        for (int i = 1; i < size; i++) {
            array[i - 1] = array[i];
        }

        size--;  // Reducing size by 1
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
