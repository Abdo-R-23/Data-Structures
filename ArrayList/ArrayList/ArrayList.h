#pragma once
#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* arr;        // ?????? ???? ?????? ??? ???????? ?? ???????
    int capacity;  // ????? ??????? ????????
    int size;      // ??? ??????? ???????

    void resize(int newCapacity) {
        T* newArr = new T[newCapacity]; // ?????? ????
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i]; // ??? ???????
        }
        delete[] arr; // ??? ???????
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor ????
    ArrayList() {
        capacity = 4;   // ??? ????????
        size = 0;
        arr = new T[capacity];
    }

    // Constructor ????? size
    ArrayList(int initialCapacity) {
        capacity = initialCapacity;
        size = 0;
        arr = new T[capacity];
    }

    // ????? ???? ?? ???????
    void add(T value) {
        if (size == capacity) {
            resize(capacity * 2); // ?? ????? ?????
        }
        arr[size] = value;
        size++;
    }

    // ????? ?? ???? ????
    void insert(int index, T value) {
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    // ??? ???? ??? index ????
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // ????? ???????
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~ArrayList() {
        delete[] arr;
    }
};

