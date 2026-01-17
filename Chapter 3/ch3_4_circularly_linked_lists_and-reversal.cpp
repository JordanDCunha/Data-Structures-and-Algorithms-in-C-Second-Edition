/**
 * CHAPTER 3.4: CIRCULARLY LINKED LISTS & REVERSAL
 * --- THE CONCEPT ---
 * 1. Circularity: The tail's 'next' pointer points back to the head, forming a cycle.
 * 2. Cursor: Instead of head/tail, we use a 'cursor' to track our current position.
 * 3. Front vs. Back: The 'back' is the node at the cursor; the 'front' is the node after the cursor.
 * 4. Use Case: Ideal for round-robin scheduling or looping playlists.
 */

#include <iostream>
#include <string>

using namespace std;

typedef string Elem;

// =============================================================================
// 3.4.1 CIRCULARLY LINKED LIST IMPLEMENTATION
// =============================================================================

class CNode {                        // Circularly linked list node
private:
    Elem elem;                       
    CNode* next;                     
    friend class CircleList;         
};



class CircleList {                   // A circularly linked list
public:
    CircleList();                    // Constructor
    ~CircleList();                   // Destructor
    bool empty() const;              // Is list empty?
    const Elem& front() const;       // Element following cursor
    const Elem& back() const;        // Element at cursor
    void advance();                  // Advance cursor
    void add(const Elem& e);         // Add node after cursor
    void remove();                   // Remove node after cursor
private:
    CNode* cursor;                   // The cursor
};

CircleList::CircleList() : cursor(NULL) { }

CircleList::~CircleList() { while (!empty()) remove(); }

bool CircleList::empty() const { return cursor == NULL; }

const Elem& CircleList::back() const { return cursor->elem; }

const Elem& CircleList::front() const { return cursor->next->elem; }

void CircleList::advance() { cursor = cursor->next; }

/**
 * INSERTION:
 * If empty: Node points to itself, cursor points to it.
 * If not empty: New node is placed between cursor and cursor->next.
 */

void CircleList::add(const Elem& e) {
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL) {
        v->next = v;                 // Self-loop
        cursor = v;
    } else {
        v->next = cursor->next;      // Link v to the old "front"
        cursor->next = v;            // Cursor now links to v
    }
}

/**
 * REMOVAL:
 * Removes the node AFTER the cursor.
 */
void CircleList::remove() {
    CNode* old = cursor->next;       // The node following cursor
    if (old == cursor) {             // Only one node in list
        cursor = NULL;
    } else {
        cursor->next = old->next;    // Skip over old node
    }
    delete old;
}

// =============================================================================
// 3.4.2 LIST REVERSAL
// =============================================================================

/**
 * Reverses a Doubly Linked List L using a temporary list T.
 * 1. Move L.front() to T.addFront() -> This reverses the order.
 * 2. Move T.front() to L.addBack()  -> This maintains the new reversed order.
 */

void listReverse(DLinkedList& L) { 
    DLinkedList T; 
    while (!L.empty()) {             // Phase 1: Reverse L into T
        string s = L.front(); 
        L.removeFront();
        T.addFront(s);
    }
    while (!T.empty()) {             // Phase 2: Copy T back to L
        string s = T.front(); 
        T.removeFront();
        L.addBack(s);
    }
}

// =============================================================================
// MAIN EXECUTION: DISCO PLAYLIST
// =============================================================================

int main() {
    CircleList playList;
    
    // Initial Playlist
    playList.add("Stayin Alive");    // [Stayin Alive*]
    playList.add("Le Freak");        // [Le Freak, Stayin Alive*]
    playList.add("Jive Talkin");     // [Jive Talkin, Le Freak, Stayin Alive*]

    // Replacement logic: Replace "Stayin Alive" with "Disco Inferno"
    playList.advance();              // Cursor moves to "Le Freak"
    playList.advance();              // Cursor moves to "Stayin Alive"
    
    // "Stayin Alive" is now back(), the node following the cursor is "Jive Talkin"
    // To remove "Stayin Alive", we need it to be AFTER the cursor.
    // Let's reposition:
    playList.advance();              // Cursor on "Jive Talkin"
    playList.advance();              // Cursor on "Le Freak"
    
    playList.remove();               // Removes node after Le Freak ("Stayin Alive")
    playList.add("Disco Inferno");   // Adds "Disco Inferno" after Le Freak
    
    cout << "Current Song (Back): " << playList.back() << endl; // Disco Inferno
    cout << "Next Song (Front): " << playList.front() << endl;  // Jive Talkin

    return 0;
}
