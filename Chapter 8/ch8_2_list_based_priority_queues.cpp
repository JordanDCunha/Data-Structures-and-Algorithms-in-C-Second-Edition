/**
 * CHAPTER 8.2: LIST-BASED PRIORITY QUEUES
 * --- THE CONCEPT ---
 * A Priority Queue can be implemented using a Doubly Linked List. 
 * The trade-off between Unsorted and Sorted implementations determines 
 * which phase of the sorting process is the bottleneck.
 */

#include <iostream>
#include <list>

using namespace std;

// =============================================================================
// 8.2.1 PERFORMANCE COMPARISON
// =============================================================================
/*
 * | Operation  | Unsorted List | Sorted List |
 * |------------|---------------|-------------|
 * | insert     | O(1)          | O(n)        |
 * | min        | O(n)          | O(1)        |
 * | removeMin  | O(n)          | O(1)        |
 */



// =============================================================================
// 8.2.2 C++ IMPLEMENTATION (SORTED LIST)
// =============================================================================

template <typename E, typename C>
class ListPriorityQueue {
public:
    int size() const { return L.size(); }
    bool empty() const { return L.empty(); }

    /**
     * INSERT: O(n)
     * Logic: Iterate through the list until we find an element larger than 'e'.
     */
    void insert(const E& e) {
        typename std::list<E>::iterator p = L.begin();
        // Skip elements smaller than e
        while (p != L.end() && !isLess(e, *p)) ++p; 
        L.insert(p, e); // STL list insert is O(1) given iterator
    }

    /**
     * MIN/REMOVEMIN: O(1)
     * Logic: In a sorted list, the smallest element is always at the front.
     */
    const E& min() const { return L.front(); }
    void removeMin() { L.pop_front(); }

private:
    std::list<E> L; // The underlying STL list
    C isLess;       // Comparator
};

// =============================================================================
// 8.2.3 SELECTION-SORT vs. INSERTION-SORT
// =============================================================================

/**
 * SELECTION-SORT (Uses Unsorted List PQ)
 * ---
 * Phase 1 (Insert): O(n) - Just append to the end.
 * Phase 2 (Remove): O(n^2) - Search the whole list for min 'n' times.
 * Total: O(n^2)
 */



/**
 * INSERTION-SORT (Uses Sorted List PQ)
 * ---
 * Phase 1 (Insert): O(n^2) - Finding the correct spot for each of 'n' items.
 * Phase 2 (Remove): O(n) - Just grab the front element.
 * Total: O(n^2)
 * Note: Best case O(n) if the list is already sorted.
 */



// =============================================================================
// 8.2.4 SUMMARY OF SORTING PHASES
// =============================================================================
/*
 * Both algorithms result in a total complexity of O(n^2) because of the 
 * arithmetic series: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2.
 *
 * - Selection-Sort: The work is done during REMOVAL.
 * - Insertion-Sort: The work is done during INSERTION.
 */
