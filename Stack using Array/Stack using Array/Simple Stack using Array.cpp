#include <iostream>
using namespace std;

class SimpleStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    SimpleStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~SimpleStack() {
        delete[] arr;
    }

    // Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek (Top element)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    SimpleStack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70); // Overflow

    return 0;
}
