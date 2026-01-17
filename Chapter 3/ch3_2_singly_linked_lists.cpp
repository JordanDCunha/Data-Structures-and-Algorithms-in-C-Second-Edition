/**
 * CHAPTER 3.2: SINGLY LINKED LISTS
 * --- THE CONCEPT ---
 * 1. Nodes: The basic building blocks. Each stores an element and a pointer (next).
 * 2. Head & Tail: The start and end of the list. The tail's 'next' is NULL.
 * 3. Link Hopping: Moving from one node to another via pointers.
 * 4. Advantage: Dynamic size; O(1) time to add/remove at the head.
 * 5. Disadvantage: O(n) time to access middle elements or remove at the tail.
 */

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 3.2.4 IMPLEMENTING A GENERIC SINGLY LINKED LIST
// =============================================================================

/**
 * 
 */

template <typename E>
class SNode {                        // Singly linked list node
private:
    E elem;                          // Element value
    SNode<E>* next;                  // Next item in the list
    
    // Grant access to the list class
    template <typename T> friend class SLinkedList; 
};

template <typename E>
class SLinkedList {                  // A generic singly linked list
public:
    SLinkedList();                   // Constructor
    ~SLinkedList();                  // Destructor
    bool empty() const;              // Is list empty?
    const E& front() const;          // Return front element
    void addFront(const E& e);       // Add to front of list
    void removeFront();              // Remove front item
    
private:
    SNode<E>* head;                  // Pointer to the head of the list
};

// --- Member Function Definitions ---

template <typename E>
SLinkedList<E>::SLinkedList()        // Constructor
    : head(NULL) { }

template <typename E>
SLinkedList<E>::~SLinkedList()       // Destructor
    { while (!empty()) removeFront(); }

template <typename E>
bool SLinkedList<E>::empty() const   // Is list empty?
    { return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const // Return front element
    { return head->elem; }

/**
 * INSERTION AT FRONT:
 * 1. Create new node.
 * 2. Point new node's next to current head.
 * 3. Update head to be the new node.
 */

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNode<E>* v = new SNode<E>();    // Create new node
    v->elem = e;                     // Store data
    v->next = head;                  // New node points to old head
    head = v;                        // New node becomes the head
}

/**
 * REMOVAL FROM FRONT:
 * 1. Save pointer to current head.
 * 2. Update head to the second node.
 * 3. Delete the saved old head node.
 */

template <typename E>
void SLinkedList<E>::removeFront() {
    if (empty()) return;             // Should ideally throw exception
    SNode<E>* old = head;            // Save current head
    head = old->next;                // Skip over the old head
    delete old;                      // Free the memory
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    // List of Strings
    SLinkedList<string> airportList;
    airportList.addFront("MSP");
    airportList.addFront("SFO");
    airportList.addFront("LAX");

    cout << "Front of airport list: " << airportList.front() << endl; // LAX

    // List of Integers
    SLinkedList<int> scores;
    scores.addFront(100);
    scores.addFront(200);
    
    scores.removeFront();
    cout << "Front of scores: " << scores.front() << endl; // 100

    return 0;
}
