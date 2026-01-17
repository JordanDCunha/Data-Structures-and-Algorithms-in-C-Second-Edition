/**
 * CHAPTER 5.3: DOUBLE-ENDED QUEUES (DEQUES)
 * --- THE CONCEPT ---
 * A Deque (pronounced "deck") is a sequence that allows O(1) 
 * insertion and deletion at BOTH the front and the back.
 * It is the most general form of the linear ADTs, acting as 
 * both a Stack and a Queue simultaneously.
 */

#include <iostream>
#include <string>
#include <deque> // STL Deque

using namespace std;

// =============================================================================
// 5.3.1 THE DEQUE ADT
// =============================================================================
/*
 * CORE OPERATIONS:
 * insertFront(e), insertBack(e) : Add elements to either end.
 * eraseFront(), eraseBack()     : Remove elements from either end.
 * front(), back()               : Access elements at either end.
 */



// =============================================================================
// 5.3.2 DOUBLY LINKED LIST IMPLEMENTATION
// =============================================================================
/*
 * A Doubly Linked List is the ideal underlying structure for a Deque.
 * Because nodes have both 'next' and 'prev' pointers, we can remove 
 * from the back in O(1) time—something a singly linked list cannot do.
 */



typedef string Elem;

class LinkedDeque {
private:
    // DLinkedList D; (Assume implemented with header/trailer sentinels)
    int n; // size
public:
    LinkedDeque() : n(0) {}
    int size() const { return n; }
    bool empty() const { return n == 0; }

    // Logic: Map Deque operations directly to Doubly Linked List operations
    void insertFront(const Elem& e) { /* D.addFront(e); */ n++; }
    void insertBack(const Elem& e)  { /* D.addBack(e);  */ n++; }
    
    void removeFront() {
        if (empty()) throw runtime_error("Deque Empty");
        /* D.removeFront(); */ n--;
    }
    
    void removeBack() {
        if (empty()) throw runtime_error("Deque Empty");
        /* D.removeBack(); */ n--;
    }
};

// =============================================================================
// 5.3.3 THE ADAPTER DESIGN PATTERN
// =============================================================================
/*
 * An "Adapter" wraps an existing class to provide a different interface.
 * Since a Deque is so flexible, we can use it to implement a Stack 
 * or a Queue simply by "turning off" certain functions.
 */

class DequeStack { // Implementing a Stack using a Deque
private:
    deque<Elem> D; // Using STL deque as the internal engine
public:
    void push(const Elem& e) { D.push_front(e); } // Push to front
    void pop() { D.pop_front(); }                 // Pop from front
    const Elem& top() { return D.front(); }
    int size() const { return D.size(); }
};

// =============================================================================
// MAIN DEMONSTRATION
// =============================================================================

int main() {
    // 1. STL Deque Demo
    deque<int> myDeck;
    myDeck.push_back(10);  // (10)
    myDeck.push_front(20); // (20, 10)
    myDeck.push_back(5);   // (20, 10, 5)
    
    cout << "Front: " << myDeck.front() << endl; // 20
    cout << "Back: " << myDeck.back() << endl;   // 5
    
    myDeck.pop_front(); // Removes 20
    myDeck.pop_back();  // Removes 5
    
    // 2. Adapter Demo
    DequeStack stackAdapter;
    stackAdapter.push("Bottom");
    stackAdapter.push("Top");
    cout << "Stack Top: " << stackAdapter.top() << endl; // Top

    return 0;
}
