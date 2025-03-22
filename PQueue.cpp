#include <iostream>

using namespace std;

class PQueue {
private:
    struct PQElement {
        int value;
        int priority;

        PQElement(const int value, const int priority) : value(value), priority(priority) {}
    };

    PQElement** array;
    int size;
    int capacity;

public:
    explicit PQueue(const int capacity) {
        this->capacity = capacity;
        this->size = 0;
        array = new PQElement*[capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    // Enqueue with priority
    void enqueue(int value, int priority) {
        if (isFull()) {
            return;
        }

        PQElement* newElement = new PQElement(value, priority);

        // Insert the new element in sorted order by priority
        int i = size - 1;
        while (i >= 0 && array[i]->priority < priority) {
            array[i + 1] = array[i];  // shift the element right
            i--;
        }

        // Insert the new element at the correct position
        array[i + 1] = newElement;
        size++;
    }

    // Dequeue the highest priority element
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        const int value = array[0]->value;
        delete array[0];  // Free memory

        // Shift all to the  left
        for (int i = 1; i < size; i++) {
            array[i - 1] = array[i];
        }

        size--; // reducing size by 1
        return value;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }

        return array[0]->value;
    }


    ~PQueue() {
        for (int i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;  // Delete the array
    }
};