#ifndef PQUEUE_HPP
#define PQUEUE_HPP


template <typename T>
class PQueue {
private:
    T** array;
    int size;
    int capacity;
public:
    explicit PQueue(int capacity);
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const int source, const int dest, const int weight);
    T* dequeue();
    T* peek() const;
    // int getDest(const T* element) const;
    // int getWeight(const T* element) const;
    ~PQueue();
};

#endif // PQUEUE_HPP
