/**
 * CHAPTER 3.3: DOUBLY LINKED LISTS
 * --- THE CONCEPT ---
 * 1. Bidirectional: Each node has 'next' and 'prev' pointers.
 * 2. Sentinels: Special 'header' and 'trailer' nodes simplify logic by 
 * eliminating null-pointer edge cases.
 * 3. Efficiency: Insertion and removal at any known position is O(1).
 * 4. Versatility: Can easily remove from the tail, unlike singly linked lists.
 */

#include <iostream>
#include <string>

using namespace std;

typedef string Elem;                    // Define the element type

// =============================================================================
// 3.3.3 C++ IMPLEMENTATION
// =============================================================================

class DNode {                           // Doubly linked list node
private:
    Elem elem;                          // Node element value
    DNode* prev;                        // Previous node in list
    DNode* next;                        // Next node in list
    friend class DLinkedList;           // Allow DLinkedList access
};



class DLinkedList {                     // Doubly linked list
public:
    DLinkedList();                      // Constructor
    ~DLinkedList();                     // Destructor
    bool empty() const;                 // Is list empty?
    const Elem& front() const;          // Get front element
    const Elem& back() const;           // Get back element
    void addFront(const Elem& e);       // Add to front of list
    void addBack(const Elem& e);        // Add to back of list
    void removeFront();                 // Remove from front
    void removeBack();                  // Remove from back

private:
    DNode* header;                      // List sentinel: start
    DNode* trailer;                     // List sentinel: end

protected:                              // Local utilities
    void add(DNode* v, const Elem& e);  // Insert new node before v
    void remove(DNode* v);              // Remove node v
};

// --- Constructor and Destructor ---

DLinkedList::DLinkedList() {
    header = new DNode;                 // Create sentinels
    trailer = new DNode;
    header->next = trailer;             // Point to each other initially
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}



DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();     // Remove all data nodes
    delete header;                      // Clean up sentinels
    delete trailer;
}

// --- Accessors ---

bool DLinkedList::empty() const {
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

// --- Insertion Logic ---

/**
 * add(v, e): Inserts a new node BEFORE node v.
 */

void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode; 
    u->elem = e;
    u->next = v;                        // New node points forward to v
    u->prev = v->prev;                  // New node points back to v's predecessor
    v->prev->next = u;                  // Predecessor points forward to new node
    v->prev = u;                        // v points back to new node
}

void DLinkedList::addFront(const Elem& e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) {
    add(trailer, e);
}

// --- Removal Logic ---

/**
 * remove(v): "Links out" node v by connecting its neighbors directly.
 */

void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev;                 // Predecessor
    DNode* w = v->next;                 // Successor
    u->next = w;                        // Connect predecessor to successor
    w->prev = u;                        // Connect successor to predecessor
    delete v;
}

void DLinkedList::removeFront() {
    if (!empty()) remove(header->next);
}

void DLinkedList::removeBack() {
    if (!empty()) remove(trailer->prev);
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    DLinkedList list;
    
    list.addFront("JFK");
    list.addBack("SFO");
    list.addBack("PVD");
    
    cout << "Front: " << list.front() << endl; // JFK
    cout << "Back:  " << list.back() << endl;  // PVD
    
    list.removeBack();                         // Removes PVD
    cout << "New Back: " << list.back() << endl; // SFO
    
    return 0;
}
