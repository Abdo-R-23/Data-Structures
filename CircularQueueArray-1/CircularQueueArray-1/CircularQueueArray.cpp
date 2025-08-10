#include <iostream>
using namespace std;

class CircularQueueArray {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    CircularQueueArray(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueueArray() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueueArray cq(5);

    for (int i = 1; i <= 5; i++) cq.enqueue(i * 10);
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}
