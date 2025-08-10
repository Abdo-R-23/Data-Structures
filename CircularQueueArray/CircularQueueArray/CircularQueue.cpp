

#include <iostream>
using namespace std;
#include"CircularQueue.h";

// =======================
// Main Program
// =======================
int main() {
    CircularQueue q(5); // ??? ??? Queue

    int choice, value;
    do {
        cout << "\n===== Circular Queue Menu =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << (q.isEmpty() ? "? Queue is EMPTY" : "? Queue is NOT empty") << endl;
            break;

        case 5:
            cout << (q.isFull() ? "? Queue is FULL" : "? Queue is NOT full") << endl;
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

