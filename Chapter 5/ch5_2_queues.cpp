/**
 * CHAPTER 5.2: QUEUES
 * --- THE CONCEPT ---
 * A Queue is a FIFO (First-In, First-Out) data structure.
 * Think of a line (queue) at an amusement park: the first person
 * to join the line is the first person to get on the ride.
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue> // STL Queue

using namespace std;

// =============================================================================
// 5.2.1 THE QUEUE ADT
// =============================================================================
/*
 * CORE OPERATIONS:
 * enqueue(e): Add element e to the REAR.
 * dequeue():  Remove the element from the FRONT.
 * front():    Return a reference to the FRONT element.
 * size():     Return number of elements.
 * empty():    Boolean check if queue is empty.
 */



// =============================================================================
// 5.2.2 ARRAY-BASED CIRCULAR QUEUE
// =============================================================================
/*
 * Problem: A simple array fills up at the "rear" and empties at the "front".
 * If we just increment pointers, we run out of space even if the front is empty.
 * Solution: CIRCULAR ARRAY using the modulo operator (%).
 * * f: index of front element
 * r: index of next available rear slot
 * Formula: f = (f + 1) % Capacity
 */



template <typename E>
class ArrayQueue {
private:
    E* Q;               // Array storage
    int capacity;       // Max size
    int f;              // Front index
    int r;              // Rear index
    int n;              // Current size
public:
    ArrayQueue(int cap = 100) : Q(new E[cap]), capacity(cap), f(0), r(0), n(0) {}

    int size() const { return n; }
    bool empty() const { return n == 0; }

    const E& front() const {
        if (empty()) throw runtime_error("Queue Empty");
        return Q[f];
    }

    void enqueue(const E& e) {
        if (size() == capacity) throw runtime_error("Queue Full");
        Q[r] = e;
        r = (r + 1) % capacity; // Circular wrap
        n++;
    }

    void dequeue() {
        if (empty()) throw runtime_error("Queue Empty");
        f = (f + 1) % capacity; // Circular wrap
        n--;
    }
};

// =============================================================================
// 5.2.3 CIRCULARLY LINKED LIST QUEUE
// =============================================================================
/*
 * A circularly linked list is perfect for a queue.
 * The 'cursor' points to the REAR.
 * The 'cursor->next' points to the FRONT.
 */



typedef string Elem;
class LinkedQueue {
public:
    LinkedQueue() : n(0) {}
    int size() const { return n; }
    bool empty() const { return n == 0; }
    
    // front() -> returns element after cursor (the front)
    // enqueue(e) -> add after cursor, then advance cursor
    // dequeue() -> remove element after cursor
private:
    // SLinkedList or CircleList instance here
    int n;
};

// =============================================================================
// MAIN DEMONSTRATION
// =============================================================================

int main() {
    // 1. ArrayQueue Demo (Circular Logic)
    ArrayQueue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element: " << q.front() << endl; // 10
    q.dequeue();
    cout << "New Front: " << q.front() << endl;     // 20

    // 2. STL Queue Demo
    queue<string> stlQueue;
    stlQueue.push("First");  // push = enqueue
    stlQueue.push("Second");
    cout << "STL Front: " << stlQueue.front() << endl;
    stlQueue.pop();          // pop = dequeue

    return 0;
}
