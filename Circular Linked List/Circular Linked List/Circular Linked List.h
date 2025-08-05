#pragma once
#include <iostream>
using namespace std;

// Node Class
template <typename T>
class CNode {
public:
    T data;
    CNode* next;

    CNode(T value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List
template <typename T>
class CircularLinkedList {
private:
    CNode<T>* head;
    int size;

public:
    CircularLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~CircularLinkedList() {
        if (!head) return;

        CNode<T>* current = head->next;
        while (current != head) {
            CNode<T>* next = current->next;
            delete current;
            current = next;
        }
        delete head;
    }

    int getSize() const {
        return size;
    }

    void addLast(T value) {
        insertAt(size, value);
    }

    void insertAt(int index, T value) {
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");

        CNode<T>* newNode = new CNode<T>(value);

        if (index == 0) {
            if (!head) {
                head = newNode;
                newNode->next = newNode;
            }
            else {
                CNode<T>* tail = head;
                while (tail->next != head)
                    tail = tail->next;

                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
        }
        else {
            CNode<T>* temp = head;
            for (int i = 0; i < index - 1; i++)
                temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }

        size++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");

        if (index == 0) {
            if (size == 1) {
                delete head;
                head = nullptr;
            }
            else {
                CNode<T>* tail = head;
                while (tail->next != head)
                    tail = tail->next;

                CNode<T>* toDelete = head;
                head = head->next;
                tail->next = head;
                delete toDelete;
            }
        }
        else {
            CNode<T>* temp = head;
            for (int i = 0; i < index - 1; i++)
                temp = temp->next;

            CNode<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }

        size--;
    }

    void print() const {
        if (!head) {
            cout << "Empty List\n";
            return;
        }

        CNode<T>* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

