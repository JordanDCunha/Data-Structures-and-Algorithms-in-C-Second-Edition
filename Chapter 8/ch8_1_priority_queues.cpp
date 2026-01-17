/**
 * CHAPTER 8.1: PRIORITY QUEUES
 * --- THE CONCEPT ---
 * A Priority Queue is an ADT that stores prioritized elements. Unlike linear 
 * structures (Stacks/Queues), it allows arbitrary insertion but only supports 
 * removal of the element with the "first" priority (typically the minimum key).
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// =============================================================================
// 8.1.1 TOTAL ORDER RELATIONS
// =============================================================================
/*
 * For a comparison rule (<=) to be a Total Order, it must satisfy:
 * 1. Reflexive: k <= k
 * 2. Antisymmetric: if k1 <= k2 and k2 <= k1, then k1 = k2
 * 3. Transitive: if k1 <= k2 and k2 <= k3, then k1 <= k3
 */



// =============================================================================
// 8.1.2 COMPARATORS (The Function Object Pattern)
// =============================================================================
/* * Comparators decouple the data type from the comparison logic.
 * In C++, this is achieved by overloading the operator().
 */

class Point2D {
public:
    Point2D(double x, double y) : _x(x), _y(y) {}
    double getX() const { return _x; }
    double getY() const { return _y; }
private:
    double _x, _y;
};

// A Left-to-Right Comparator
class LeftRight {
public:
    bool operator()(const Point2D& p, const Point2D& q) const {
        return p.getX() < q.getX();
    }
};

// A Bottom-to-Top Comparator
class BottomTop {
public:
    bool operator()(const Point2D& p, const Point2D& q) const {
        return p.getY() < q.getY();
    }
};

// =============================================================================
// 8.1.3 PRIORITY QUEUE INTERFACE (ADT)
// =============================================================================

template <typename E, typename C>
class PriorityQueue {
public:
    // Core Functions
    int size() const;                   // Number of elements
    bool isEmpty() const;               // Is queue empty?
    void insert(const E& e);            // Insert element e
    const E& min() const;               // Reference to min element
    void removeMin();                   // Remove the min element
};

// =============================================================================
// 8.1.4 PRIORITY QUEUE SORTING SCHEME
// =============================================================================
/*
 * PriorityQueueSort(L, P):
 * 1. Insert all elements of List L into Priority Queue P. (Phase 1)
 * 2. RemoveMin from P and push back into L until P is empty. (Phase 2)
 */

template <typename E, typename C>
void PriorityQueueSort(std::list<E>& L, PriorityQueue<E, C>& P) {
    while (!L.empty()) {
        P.insert(L.front());
        L.pop_front();
    }
    while (!P.isEmpty()) {
        L.push_back(P.min());
        P.removeMin();
    }
}

// =============================================================================
// 8.1.5 STL PRIORITY_QUEUE (std::priority_queue)
// =============================================================================
/*
 * Note: STL defaults to a MAX-priority queue (largest element at top).
 * Syntax: priority_queue<Type, Container, Comparator>
 */

#include <queue>

void stlExample() {
    // Standard Max-PQ (Largest integer first)
    priority_queue<int> maxPQ;

    // Min-PQ (Smallest integer first) using std::greater
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(5);
    minPQ.push(2);
    minPQ.push(9);

    // minPQ.top() returns 2
    // minPQ.pop() removes 2
}



// =============================================================================
// PERFORMANCE SUMMARY
// =============================================================================
/*
 * The performance depends on the implementation (Chapter 8.2-8.3):
 * * 1. Unsorted List: Insert O(1), RemoveMin O(n)
 * 2. Sorted List:   Insert O(n), RemoveMin O(1)
 * 3. Heap:          Insert O(log n), RemoveMin O(log n)
 */
