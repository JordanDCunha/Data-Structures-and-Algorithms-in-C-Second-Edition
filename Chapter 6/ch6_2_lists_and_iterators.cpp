/**
 * CHAPTER 6.2: LISTS AND ITERATORS
 * --- THE CONCEPT ---
 * While Vectors use indices (integers) to find elements, Lists use "Positions."
 * A Position (abstracted as an Iterator) represents a specific "place" in the 
 * container. This allows for O(1) insertions and deletions anywhere in the 
 * list, provided you already have a reference to that position.
 */

#include <iostream>
#include <list>    // STL List
#include <vector>

using namespace std;

// =============================================================================
// 6.2.1 THE ITERATOR ADT
// =============================================================================
/*
 * An Iterator is an abstraction of a pointer. It supports:
 * *p:    Dereference to get the element.
 * ++p:   Advance to the next position.
 * --p:   Move to the previous position (if bidirectional).
 * ==/!=: Compare two positions.
 */



// =============================================================================
// 6.2.2 DOUBLY LINKED LIST IMPLEMENTATION (NodeList)
// =============================================================================

typedef int Elem;

class NodeList {
private:
    // Nested Node Structure
    struct Node {
        Elem elem;
        Node* prev;
        Node* next;
    };

public:
    // Nested Iterator Class
    class Iterator {
    public:
        Elem& operator*() { return v->elem; }
        bool operator==(const Iterator& p) const { return v == p.v; }
        bool operator!=(const Iterator& p) const { return v != p.v; }
        Iterator& operator++() { v = v->next; return *this; }
        Iterator& operator--() { v = v->prev; return *this; }
        friend class NodeList;
    private:
        Node* v;
        Iterator(Node* u) : v(u) {} // Private constructor
    };

private:
    int n;          // size
    Node* header;   // sentinel
    Node* trailer;  // sentinel

public:
    NodeList() {
        n = 0;
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }

    Iterator begin() const { return Iterator(header->next); }
    Iterator end() const   { return Iterator(trailer); }

    // O(1) Insertion before position p
    void insert(const Iterator& p, const Elem& e) {
        Node* w = p.v;
        Node* u = w->prev;
        Node* v = new Node{e, u, w};
        w->prev = v;
        u->next = v;
        n++;
    }

    // O(1) Erasure at position p
    void erase(const Iterator& p) {
        Node* v = p.v;
        Node* w = v->next;
        Node* u = v->prev;
        u->next = w;
        w->prev = u;
        delete v;
        n--;
    }
};



// =============================================================================
// 6.2.3 STL LISTS AND CONTAINERS
// =============================================================================
/*
 * STL provides `std::list` (doubly linked) and `std::vector` (array-based).
 * Iterators allow us to write code that works for BOTH.
 */

// Generic-style sum using Iterators (Works for any container)
int sumContainer(const vector<int>& V) {
    // We use const_iterator because the input is a const reference
    typedef vector<int>::const_iterator ConstIter;
    int sum = 0;
    for (ConstIter p = V.begin(); p != V.end(); ++p) {
        sum += *p;
    }
    return sum;
}

// =============================================================================
// MAIN DEMONSTRATION
// =============================================================================

int main() {
    // 1. Using our NodeList
    NodeList L;
    L.insert(L.begin(), 8);   // (8)
    NodeList::Iterator p = L.begin();
    L.insert(L.end(), 5);     // (8, 5)
    
    NodeList::Iterator q = p;
    ++q;                      // q points to 5
    L.insert(q, 3);           // (8, 3, 5) - insert 3 BEFORE q
    
    cout << "NodeList contents: ";
    for (NodeList::Iterator it = L.begin(); it != L.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 2. Using STL List
    list<float> stlList;
    stlList.push_back(1.5);
    stlList.push_front(2.5);  // {2.5, 1.5}
    
    cout << "STL List Front: " << stlList.front() << endl;

    return 0;
}
