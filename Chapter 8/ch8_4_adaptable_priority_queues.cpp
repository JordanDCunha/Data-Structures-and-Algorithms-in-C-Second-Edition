/**
 * CHAPTER 8.4: ADAPTABLE PRIORITY QUEUES
 * --- THE CONCEPT ---
 * Standard PQs are limited: they only allow removal of the minimum element.
 * Adaptable PQs allow us to update or remove any arbitrary element by using
 * a "Position" (or locator) returned at the time of insertion.
 */

#include <iostream>
#include <list>

using namespace std;

// =============================================================================
// 8.4.1 THE ADAPTABLE PQ ADT
// =============================================================================
/*
 * New essential operations:
 * 1. Position insert(e): Now returns a Position object for future reference.
 * 2. remove(p): Removes the specific element at Position p.
 * 3. replace(p, e): Updates the element at Position p with a new value e.
 */



// =============================================================================
// 8.4.2 LIST-BASED IMPLEMENTATION
// =============================================================================

template <typename E, typename C>
class AdaptPriorityQueue {
protected:
    typedef std::list<E> ElementList;

public:
    // Nested Position Class
    class Position {
    private:
        typename ElementList::iterator q; // Pointer to the actual list node
    public:
        const E& operator*() { return *q; }
        friend class AdaptPriorityQueue;
    };

    /**
     * INSERT: O(n)
     * Finds the correct sorted spot and returns a Position (iterator).
     */
    Position insert(const E& e) {
        typename ElementList::iterator p = L.begin();
        while (p != L.end() && !isLess(e, *p)) ++p;
        L.insert(p, e);
        Position pos; 
        pos.q = --p; // Points to the newly inserted element
        return pos;
    }

    /**
     * REMOVE: O(1)
     * Since we have the iterator (Position), deletion is instant.
     */
    void remove(const Position& p) {
        L.erase(p.q);
    }

    /**
     * REPLACE: O(n)
     * Simplest implementation: remove the old, insert the new.
     */
    Position replace(const Position& p, const E& e) {
        L.erase(p.q);
        return insert(e);
    }

private:
    ElementList L;
    C isLess;
};

// =============================================================================
// 8.4.3 LOCATION-AWARE ENTRIES (THE "LOCATOR" PATTERN)
// =============================================================================
/*
 * PROBLEM WITH HEAPS: 
 * In a Heap, bubbling moves elements between nodes. A static pointer (iterator) 
 * would eventually point to the WRONG element.
 * * SOLUTION:
 * Use "Location-Aware Entries." 
 * 1. Each entry in the heap stores the element AND a pointer to a 'Locator'.
 * 2. The Locator stores the current index of that element in the heap vector.
 * 3. When bubbling swaps two elements, the heap ALSO updates their Locators 
 * to reflect their new indices.
 */



// =============================================================================
// PERFORMANCE SUMMARY (ADAPTABLE)
// =============================================================================
/*
 * | Operation | Sorted List | Heap (with Locators) |
 * |-----------|-------------|----------------------|
 * | insert    | O(n)        | O(log n)             |
 * | remove(p) | O(1)        | O(log n)             |
 * | replace(p)| O(n)        | O(log n)             |
 * | min       | O(1)        | O(1)                 |
 */
