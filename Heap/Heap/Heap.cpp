#include <iostream>
#include <vector>
using namespace std;

// Heap Class
class Heap {
private:
    vector<int> heap;
    bool isMaxHeap; // true for Max Heap, false for Min Heap

    // Function to maintain heap property after insertion
    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;

        // For Max Heap
        if (isMaxHeap && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
        // For Min Heap
        else if (!isMaxHeap && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Function to maintain heap property after deletion
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int target = index;

        // For Max Heap
        if (isMaxHeap) {
            if (left < heap.size() && heap[left] > heap[target]) target = left;
            if (right < heap.size() && heap[right] > heap[target]) target = right;
        }
        // For Min Heap
        else {
            if (left < heap.size() && heap[left] < heap[target]) target = left;
            if (right < heap.size() && heap[right] < heap[target]) target = right;
        }

        if (target != index) {
            swap(heap[index], heap[target]);
            heapifyDown(target);
        }
    }

public:
    // Constructor to set heap type
    Heap(bool maxHeap = true) {
        isMaxHeap = maxHeap;
    }

    // Insert a new value into the heap
    void insert(int value) {
        if (heap.size() >= 15) {
            cout << "Heap is full (15 nodes max)." << endl;
            return;
        }
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Delete root element
    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Search for a value in the heap
    bool search(int value) {
        for (int num : heap) {
            if (num == value) return true;
        }
        return false;
    }

    // Display heap elements
    void display() {
        for (int num : heap) cout << num << " ";
        cout << endl;
    }
};

// Main function to test the heap
int main() {
    // Create a Max Heap
    Heap h(true);

    // Insert values
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(5);
    h.insert(20);

    cout << "Heap elements: ";
    h.display();

    // Search for a number
    int searchVal = 20;
    cout << "Searching for " << searchVal << ": "
        << (h.search(searchVal) ? "Found" : "Not Found") << endl;

    // Delete root
    cout << "Deleting root..." << endl;
    h.deleteRoot();
    h.display();

    return 0;
}
