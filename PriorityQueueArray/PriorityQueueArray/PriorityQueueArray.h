#pragma once
#include <iostream>
using namespace std;

class PriorityQueueArray {
private:
    int* arr;
    int capacity;
    int size;

public:
    PriorityQueueArray(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~PriorityQueueArray() {
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
        int i;
        for (i = size - 1; i >= 0; i--) {
            if (value < arr[i]) {
                arr[i + 1] = arr[i];
            }
            else {
                break;
            }
        }
        arr[i + 1] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Removed: " << arr[0] << endl;
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};



