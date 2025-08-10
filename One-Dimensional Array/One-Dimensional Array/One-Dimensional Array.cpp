#include <iostream>
using namespace std;

class OneDArray {
private:
    int arr[100];  // ???? ????? (????)
    int size;      // ??? ??????? ???????

public:
    // Constructor
    OneDArray() {
        size = 0;
    }

    // ????? ????
    void insert(int value) {
        if (size < 100) {
            arr[size] = value;
            size++;
        }
        else {
            cout << "Array is full!\n";
        }
    }

    // ??? ???????
    void display() {
        cout << "Array Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // ????? ?? ????
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i; // ??? ???????
            }
        }
        return -1; // ?? ?????
    }

    // ??? ????
    void remove(int value) {
        int pos = search(value);
        if (pos != -1) {
            for (int i = pos; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element removed.\n";
        }
        else {
            cout << "Element not found.\n";
        }
    }
};

int main() {
    OneDArray arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);

    arr.display();

    cout << "Searching for 20 at index: " << arr.search(20) << endl;

    arr.remove(20);
    arr.display();

    return 0;
}
