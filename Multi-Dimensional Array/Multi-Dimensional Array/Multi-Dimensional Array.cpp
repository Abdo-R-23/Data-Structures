#include <iostream>
using namespace std;

class ThreeDArray {
private:
    int arr[5][5][5]; // ?????? ?????? ??????? (??? ???? ?????)
    int x, y, z;

public:
    // Constructor
    ThreeDArray(int xSize, int ySize, int zSize) {
        x = xSize;
        y = ySize;
        z = zSize;

        // ????? ?????? ???
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    arr[i][j][k] = 0;
                }
            }
        }
    }

    // ????? ????
    void insert(int i, int j, int k, int value) {
        if (i >= 0 && i < x && j >= 0 && j < y && k >= 0 && k < z) {
            arr[i][j][k] = value;
        }
        else {
            cout << "Invalid position!\n";
        }
    }

    // ??? ????????
    void display() {
        cout << "Three-Dimensional Array:\n";
        for (int i = 0; i < x; i++) {
            cout << "Layer " << i << ":\n";
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    cout << arr[i][j][k] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    // ????? ?? ????
    bool search(int value) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    if (arr[i][j][k] == value) {
                        cout << "Found at position: (" << i << "," << j << "," << k << ")\n";
                        return true;
                    }
                }
            }
        }
        cout << "Not found.\n";
        return false;
    }
};

int main() {
    ThreeDArray arr(2, 2, 2); // ?????? 2x2x2

    arr.insert(0, 0, 0, 5);
    arr.insert(1, 1, 1, 10);

    arr.display();

    arr.search(10);
    arr.search(7);

    return 0;
}
