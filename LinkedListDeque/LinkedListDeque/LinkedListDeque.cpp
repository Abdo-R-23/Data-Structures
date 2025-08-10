#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DequeList {
private:
    Node* front;
    Node* rear;

public:
    DequeList() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        Node* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        Node* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DequeList() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};

int main() {
    DequeList dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();

    dq.deleteFront();
    dq.display();

    dq.insertRear(30);
    dq.insertRear(40);
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}
