#include <iostream>
using namespace std;

class TwoDArray {
private:
    int arr[10][10]; // ?????? 2D ????? ????? (????)
    int rows, cols;  // ??? ?????? ????????

public:
    // Constructor
    TwoDArray(int r, int c) {
        rows = r;
        cols = c;
        // ????? ???????? ?????? ???
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // ????? ????
    void insert(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            arr[row][col] = value;
        }
        else {
            cout << "Invalid position!\n";
        }
    }

    // ??? ????????
    void display() {
        cout << "Two-Dimensional Array:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // ????? ?? ????
    bool search(int value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == value) {
                    cout << "Found at position: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }
        cout << "Not found.\n";
        return false;
    }

    // ??? ???? (???? ???)
    void remove(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            arr[row][col] = 0;
            cout << "Element removed.\n";
        }
        else {
            cout << "Invalid position!\n";
        }
    }
};

int main() {
    TwoDArray arr(3, 3); // ?????? 3x3

    arr.insert(0, 0, 10);
    arr.insert(1, 1, 20);
    arr.insert(2, 2, 30);

    arr.display();

    arr.search(20);

    arr.remove(1, 1);
    arr.display();

    return 0;
}
