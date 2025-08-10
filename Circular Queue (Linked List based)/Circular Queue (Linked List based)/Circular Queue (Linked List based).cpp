#include <iostream>
using namespace std;
#include"Circular Queue (Linked List based).h";



// Main function to test the Queue
int main() {
    Queue q;

    // ????? ????? ?? 1 ??? 10
    for (int i = 1; i <= 10; i++) {
        q.enqueue(i);
    }

    q.display();

    // ??? ??????
    q.dequeue();
    q.dequeue();

    q.display();

    // ????? ????? ?????
    q.enqueue(11);
    q.enqueue(12);

    q.display();

    return 0;
}
