#pragma once
#include <iostream>
using namespace std;

// ????? Node
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

// ????? LinkedList
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void addLast(T value) {
        insertAt(size, value);
    }

    void insertAt(int index, T value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }

        Node<T>* newNode = new Node<T>(value);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        size++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        Node<T>* temp = head;

        if (index == 0) {
            head = head->next;
            delete temp;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }

        size--;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int getSize() const {
        return size;
    }
};


