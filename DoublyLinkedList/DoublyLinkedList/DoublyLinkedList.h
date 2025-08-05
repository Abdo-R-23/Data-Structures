#pragma once
#include <iostream>
using namespace std;

// ????? Node ????? ???????
template <typename T>
class DNode {
public:
    T data;
    DNode* next;
    DNode* prev;

    DNode(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// ????? DoublyLinkedList
template <typename T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
    int size;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList() {
        DNode<T>* current = head;
        while (current != nullptr) {
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }
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

        DNode<T>* newNode = new DNode<T>(value);

        if (index == 0) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            if (tail == nullptr)
                tail = newNode;
        }
        else if (index == size) {
            newNode->prev = tail;
            if (tail != nullptr)
                tail->next = newNode;
            tail = newNode;
            if (head == nullptr)
                head = newNode;
        }
        else {
            DNode<T>* temp = head;
            for (int i = 0; i < index; i++)
                temp = temp->next;

            newNode->next = temp;
            newNode->prev = temp->prev;

            if (temp->prev != nullptr)
                temp->prev->next = newNode;
            temp->prev = newNode;

            if (index == 0)
                head = newNode;
        }

        size++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");

        DNode<T>* toDelete;

        if (index == 0) {
            toDelete = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        }
        else if (index == size - 1) {
            toDelete = tail;
            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;
        }
        else {
            toDelete = head;
            for (int i = 0; i < index; i++)
                toDelete = toDelete->next;

            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
        }

        delete toDelete;
        size--;
    }

    void print() const {
        DNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

