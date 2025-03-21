class Queue {
private:
    int* array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    explicit Queue(const int capacity) {
        this->capacity = capacity;
        this->front = 0;
        this-> rear = 0;
        this-> size = 0;
        array = new int[capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return  (size == capacity);
    }

    void enqueue(int value) {
        if (!isFull()) {
            array[rear] = value;
            rear = (rear + 1) % capacity;
            ++size;
        }
    }
    int dequeue() {
        if (!isEmpty()) {
            const int value = array[front];
            front = (front + 1) % capacity;
            --size;
            return value;
        }
        return -1; // Return -1 if the queue is empty
    }

    int getFront() {
        return array[front];
    }
    int getRear() {
        return array[rear];
    }


    ~Queue() {
        delete[] array;
    }
};