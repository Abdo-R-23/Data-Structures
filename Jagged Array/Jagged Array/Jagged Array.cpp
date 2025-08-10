#include <iostream>
using namespace std;

class JaggedArray {
private:
    int** arr; // ???? ???????
    int rows;
    int* colSizes; // ??? ??????? ??? ??

public:
    // Constructor
    JaggedArray(int r, int colsPerRow[]) {
        rows = r;
        arr = new int* [rows];
        colSizes = new int[rows];

        for (int i = 0; i < rows; i++) {
            colSizes[i] = colsPerRow[i];
            arr[i] = new int[colSizes[i]]; // ????? ?? ???? ????? ?????
            for (int j = 0; j < colSizes[i]; j++) {
                arr[i][j] = 0; // ????? ?????? ???
            }
        }
    }

    // ????? ????
    void insert(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < colSizes[row]) {
            arr[row][col] = value;
        }
        else {
            cout << "Invalid position!\n";
        }
    }

    // ??? ????????
    void display() {
        cout << "Jagged Array:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colSizes[i]; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Destructor
    ~JaggedArray() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] colSizes;
    }
};

int main() {
    int colsPerRow[] = { 3, 5, 2 }; // ???? ????? 3 ?????? ?????? 5? ?????? 2
    JaggedArray arr(3, colsPerRow);

    arr.insert(0, 0, 10);
    arr.insert(1, 4, 20);
    arr.insert(2, 1, 30);

    arr.display();

    return 0;
}
