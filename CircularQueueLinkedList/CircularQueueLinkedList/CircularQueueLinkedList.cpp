#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueueLinkedList {
private:
    Node* rear;

public:
    CircularQueueLinkedList() : rear(nullptr) {}

    ~CircularQueueLinkedList() {
        while (!isEmpty()) dequeue();
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        }
        else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* front = rear->next;
        if (rear == front) {
            rear = nullptr;
        }
        else {
            rear->next = front->next;
        }
        cout << front->data << " dequeued\n";
        delete front;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        Node* temp = rear->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << "\n";
    }
};

int main() {
    CircularQueueLinkedList cq;

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
