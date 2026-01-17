/**
 * CHAPTER 8: EXERCISES & SOLUTIONS
 * --- OVERVIEW ---
 * This file contains the conceptual and implementation-based solutions 
 * for Chapter 8 (Priority Queues & Heaps).
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// =============================================================================
// REINFORCEMENT SOLUTIONS
// =============================================================================

/**
 * R-8.1: STL priority_queue Running Times
 * - size(), empty(): O(1)
 * - push(e): O(log n)
 * - top(): O(1)
 * - pop(): O(log n)
 */

/**
 * R-8.2: Removing log(n) smallest elements
 * Each removeMin() takes O(log n) time.
 * Total time = log(n) * O(log n) = O((log n)^2).
 */

/**
 * R-8.3: Implementing Comparators with only < and logic
 * - (a > b)   is (b < a)
 * - (a <= b)  is !(b < a)
 * - (a >= b)  is !(a < b)
 * - (a == b)  is !(a < b) && !(b < a)
 * - (a != b)  is (a < b) || (b < a)
 */

/**
 * R-8.7: Air-Traffic Control Simulation
 * Structure: Heap (Priority Queue).
 * Why: We need frequent insertions (future events) and frequent 
 * "extract-min" (next event to process). Heaps handle both in O(log n).
 */

/**
 * R-8.12: Largest Key Location
 * In a Min-Heap, the largest key must be stored in one of the 
 * LEAF nodes (External nodes).
 */



// =============================================================================
// CREATIVITY & PROJECT SOLUTIONS
// =============================================================================

/**
 * C-8.4: Stack using Priority Queue
 * Logic: Use a "counter" as the key. Each new insertion gets a higher priority 
 * (counter--). The "min" will always be the most recently added item (LIFO).
 */
template <typename E>
class PQStack {
private:
    priority_queue<pair<int, E>> pq;
    int counter;
public:
    PQStack() : counter(0) {}
    void push(const E& e) { pq.push({counter++, e}); } // Max-PQ uses counter
    void pop() { pq.pop(); }
    E top() { return pq.top().second; }
};

/**
 * C-8.7: In-Place Selection Sort
 * Space: O(1) additional variables.
 */
void inPlaceSelectionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIdx]) minIdx = j;
        }
        swap(A[i], A[minIdx]);
    }
}



/**
 * P-8.4: In-Place Heap Sort Implementation
 * Phase 1: Build Max-Heap in place.
 * Phase 2: Repeatedly swap root to end and down-heap.
 */
void heapify(vector<int>& A, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void inPlaceHeapSort(vector<int>& A) {
    int n = A.size();
    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) heapify(A, n, i);
    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}



// =============================================================================
// SUMMARY TABLE
// =============================================================================
/*
 * | Algorithm      | Average Time | Worst Case | Space |
 * |----------------|--------------|------------|-------|
 * | Selection Sort | O(n^2)       | O(n^2)     | O(1)  |
 * | Insertion Sort | O(n^2)       | O(n^2)     | O(1)  |
 * | Heap Sort      | O(n log n)   | O(n log n) | O(1)  |
 */

/**
 * NEXT STEP:
 * We have completed Chapter 8. Would you like to move on to 
 * Chapter 9: Maps, Hash Tables, and Skip Lists?
 */
