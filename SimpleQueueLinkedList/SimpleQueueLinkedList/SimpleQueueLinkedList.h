#pragma once
#include <iostream>
using namespace std;

// ????? ??? Node
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// ????? ???? ??? Queue
class SimpleQueueLinkedList {
private:
    Node* front; // ??? ????
    Node* rear;  // ??? ????

public:
    // Constructor
    SimpleQueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor
    ~SimpleQueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // ????? ???? ?? ??? ???????
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // ??? ???? ?? ????? ???????
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot remove.\n";
            return;
        }
        Node* temp = front;
        cout << "Removed: " << temp->data << endl;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // ?????? ??? ??????? ????
    bool isEmpty() {
        return front == nullptr;
    }

    // ??? ????? ???????
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};




