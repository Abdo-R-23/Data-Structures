#include <iostream>
using namespace std;
#include"PriorityQueueArray.h";

int main() {
    PriorityQueueArray pq(10);

    pq.enqueue(5);
    pq.enqueue(1);
    pq.enqueue(3);
    pq.enqueue(10);
    pq.enqueue(2);

    pq.display();

    pq.dequeue();
    pq.display();

    pq.enqueue(0);
    pq.display();

    return 0;
}