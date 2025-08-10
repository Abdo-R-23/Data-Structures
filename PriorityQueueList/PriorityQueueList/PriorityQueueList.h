#pragma once
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class PriorityQueueList {
private:
    Node* front;

public:
    PriorityQueueList() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty() || value < front->data) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->data <= value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Removed: " << front->data << endl;
        front = front->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Priority Queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



