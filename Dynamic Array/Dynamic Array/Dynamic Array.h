#pragma once
template <typename T>
class ArrayList {
private:
    T* data;
    int capacity;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ArrayList() {
        capacity = 4;
        size = 0;
        data = new T[capacity];
    }

    ArrayList(int initialSize) {
        capacity = initialSize;
        size = 0;
        data = new T[capacity];
    }

    ~ArrayList() {
        delete[] data;
    }

    void add(T element) {
        if (size == capacity) {
            resize();
        }
        data[size] = element;
        size++;
    }

    void insert(int index, T element) {
        if (index < 0 || index > size) {
            throw out_of_range("Invalid index!");
        }

        if (size == capacity) {
            resize();
        }

        // ???? ??????? ?????? ?? index
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = element;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index!");
        }

        // ???? ??????? ?????? ?????? ?????? ???????
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index!");
        }
        return data[index];
    }
};

