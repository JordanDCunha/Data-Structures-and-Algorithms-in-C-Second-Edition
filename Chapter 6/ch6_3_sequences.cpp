/**
 * CHAPTER 6.3: SEQUENCES
 * --- THE CONCEPT ---
 * A Sequence is the "Super-ADT" that bridges the gap between Vectors and Lists.
 * It allows you to access elements using BOTH:
 * 1. Indices (Rank-based): e.g., atIndex(i)
 * 2. Positions (Iterator-based): e.g., indexOf(p)
 */

#include <iostream>
#include <vector>
#include <stdexcept>

// Assuming NodeList from previous chapter is available
// We inherit NodeSequence from NodeList to get position-based logic for free.

typedef int Elem;

class NodeSequence : public NodeList {
public:
    /**
     * BRIDGE FUNCTION: Index -> Position
     * Time Complexity: O(n) for Linked List (must hop through nodes)
     */
    Iterator atIndex(int i) const {
        Iterator p = begin();
        for (int j = 0; j < i; j++) {
            ++p;
        }
        return p;
    }

    /**
     * BRIDGE FUNCTION: Position -> Index
     * Time Complexity: O(n) for Linked List (must count from start)
     */
    int indexOf(const Iterator& p) const {
        Iterator q = begin();
        int j = 0;
        while (q != p) {
            ++q;
            ++j;
        }
        return j;
    }
};

// =============================================================================
// IMPLEMENTATION TRADE-OFFS
// =============================================================================
/*
 * Circular Array Implementation:
 * - atIndex(i) is O(1) (Direct pointer math)
 * - insert(p, e) is O(n) (Shifting required)
 * * Doubly Linked List Implementation:
 * - atIndex(i) is O(n) (Pointer hopping)
 * - insert(p, e) is O(1) (Just relink nodes)
 */



// =============================================================================
// CASE STUDY: BUBBLE SORT
// =============================================================================
/*
 * Bubble sort logic: Compare neighbors and swap if out of order.
 * We must be careful HOW we access the sequence.
 */

// POOR PERFORMANCE on Linked Lists: O(n^3)
// Because S.atIndex(j) is O(n) and it's inside a nested loop.
void bubbleSortIndexBased(NodeSequence& S) {
    int n = S.size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            NodeList::Iterator prec = S.atIndex(j - 1); // O(n) hop!
            NodeList::Iterator succ = S.atIndex(j);     // O(n) hop!
            if (*prec > *succ) {
                int tmp = *prec; *prec = *succ; *succ = tmp;
            }
        }
    }
}

// HIGH PERFORMANCE on all Sequences: O(n^2)
// Because we use iterators and ++ (which is always O(1)).
void bubbleSortIteratorBased(NodeSequence& S) {
    int n = S.size();
    for (int i = 0; i < n; i++) {
        NodeList::Iterator prec = S.begin();
        for (int j = 1; j < n - i; j++) {
            NodeList::Iterator succ = prec;
            ++succ; // O(1)
            if (*prec > *succ) {
                int tmp = *prec; *prec = *succ; *succ = tmp;
            }
            ++prec; // O(1)
        }
    }
}



// =============================================================================
// SUMMARY TABLE
// =============================================================================
/*
 | Operation       | Circular Array | Linked List |
 |-----------------|----------------|-------------|
 | atIndex(i)      | O(1)           | O(n)        |
 | indexOf(p)      | O(1)           | O(n)        |
 | insertFront/Back| O(1)           | O(1)        |
 | insert(p, e)    | O(n)           | O(1)        |
 | erase(p)        | O(n)           | O(1)        |
 */

int main() {
    NodeSequence S;
    S.insertBack(10);
    S.insertBack(30);
    S.insertBack(20);
    S.insertBack(5);

    std::cout << "Sorting sequence..." << std::endl;
    bubbleSortIteratorBased(S);

    std::cout << "Sorted sequence: ";
    for (auto it = S.begin(); it != S.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
