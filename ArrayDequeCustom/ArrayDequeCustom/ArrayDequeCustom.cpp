#include <iostream>
using namespace std;

class DequeArray {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    DequeArray(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = capacity - 1;
        }
        else {
            front--;
        }
        arr[front] = value;
        size++;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = 0;
        }
        else if (front == capacity - 1) {
            front = 0;
        }
        else {
            front++;
        }
        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = 0;
        }
        else if (rear == 0) {
            rear = capacity - 1;
        }
        else {
            rear--;
        }
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~DequeArray() {
        delete[] arr;
    }
};

int main() {
    DequeArray dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();

    dq.deleteFront();
    dq.display();

    dq.insertRear(30);
    dq.insertRear(40);
    dq.insertRear(50);
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}
