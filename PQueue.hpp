#ifndef PQUEUE_HPP
#define PQUEUE_HPP

#include "Node.hpp"

class PQueue {
private:
    Node** array;
    int size;
    int capacity;

public:
    // Constructor
    explicit PQueue(int capacity);


    bool isEmpty() const;
    bool isFull() const;

    // overloading because I am lazy to redo it
    void enqueue(const int source, const int dest, const int weight);
    void enqueue(int node, int priority);


    Node* dequeue();
    Node* peek() const;

    // Helper functions, if needed
    int getDest(const Node* element) const;
    int getWeight(const Node* element) const;

    ~PQueue();
};

#endif // PQUEUE_HPP
