#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Restores heap property after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Restores heap property after deletion
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert an element into heap
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove maximum element (root)
    void pop() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Get maximum element
    int top() const {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    // Print heap elements (for debugging)
    void print() const {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.push(10);
    h.push(40);
    h.push(20);
    h.push(30);
    h.push(50);

    cout << "Heap elements: ";
    h.print();

    cout << "Top element: " << h.top() << endl;

    h.pop();
    cout << "After removing top element:\n";
    h.print();

    return 0;
}
