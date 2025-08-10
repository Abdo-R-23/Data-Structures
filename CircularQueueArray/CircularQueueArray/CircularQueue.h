#pragma once
#include <iostream>
using namespace std;

// =======================
// Circular Queue Class
// =======================
class CircularQueue {
private:
    int* arr;        // ???????? ???????????
    int front;       // ????? ??? queue
    int rear;        // ????? ??? queue
    int size;        // ????? ?????
    int count;       // ??? ??????? ???????

public:
    // Constructor
    CircularQueue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // ?????? ??? ???? ?????
    bool isEmpty() {
        return count == 0;
    }

    // ?????? ??? ???? ??????
    bool isFull() {
        return count == size;
    }

    // ????? ????
    void enqueue(int value) {
        if (isFull()) {
            cout << "?? Queue is FULL! Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) front = 0; // ??? ?????
        rear = (rear + 1) % size;   // ?????? ????????
        arr[rear] = value;
        count++;
        cout << "? Enqueued: " << value << endl;
    }

    // ??? ????
    void dequeue() {
        if (isEmpty()) {
            cout << "?? Queue is EMPTY! Cannot dequeue.\n";
            return;
        }

        cout << "?? Dequeued: " << arr[front] << endl;
        front = (front + 1) % size;
        count--;

        if (count == 0) { // ?? ???? ????? ???? ????????
            front = -1;
            rear = -1;
        }
    }

    // ??? ???????
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

