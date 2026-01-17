/**
 * CHAPTER 8.3: HEAPS
 * --- THE CONCEPT ---
 * A Heap is a binary tree that balances the efficiency of insertions and removals.
 * It provides O(log n) time for both, making it far superior to list-based 
 * priority queues for large datasets.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// 8.3.1 THE HEAP PROPERTIES
// =============================================================================
/*
 * 1. Heap-Order Property: For every node v (except root), Key(v) >= Key(parent(v)).
 * Result: The root always holds the minimum element.
 * * 2. Complete Binary Tree Property: 
 * - All levels are full except possibly the last.
 * - The last level is filled from left to right.
 * - Height h = floor(log n).
 */



// =============================================================================
// 8.3.2 VECTOR-BASED REPRESENTATION
// =============================================================================
/*
 * Heaps are almost always implemented using an array/vector (no explicit pointers).
 * For a node at index i:
 * - Left Child:  2 * i
 * - Right Child: 2 * i + 1
 * - Parent:      floor(i / 2)
 * Note: Index 0 is usually left empty to make the math cleaner.
 */

template <typename E>
class VectorCompleteTree {
public:
    typedef typename std::vector<E>::iterator Position;
    VectorCompleteTree() : V(1) {} // V[0] is a placeholder
    int size() const { return V.size() - 1; }
    Position pos(int i) { return V.begin() + i; }
    int idx(const Position& p) const { return p - V.begin(); }
    
    // Navigation logic
    Position root() { return pos(1); }
    Position last() { return pos(size()); }
    void addLast(const E& e) { V.push_back(e); }
    void removeLast() { V.pop_back(); }
    void swap(const Position& p, const Position& q) { std::swap(*p, *q); }
private:
    std::vector<E> V;
};

// =============================================================================
// 8.3.3 HEAP OPERATIONS (UP-HEAP & DOWN-HEAP)
// =============================================================================

template <typename E, typename C>
class HeapPriorityQueue {
public:
    /**
     * INSERT: O(log n)
     * 1. Add element to the next available slot (maintaining completeness).
     * 2. "Up-Heap Bubbling": Swap with parent until heap-order is restored.
     */
    void insert(const E& e) {
        T.addLast(e);
        Position v = T.last();
        while (v != T.root()) {
            Position u = T.pos(T.idx(v) / 2); // parent
            if (!isLess(*v, *u)) break;
            T.swap(v, u);
            v = u;
        }
    }

    

    /**
     * REMOVEMIN: O(log n)
     * 1. Replace root with the last element in the tree.
     * 2. Remove the last node.
     * 3. "Down-Heap Bubbling": Swap with the SMALLER child until order is restored.
     */
    void removeMin() {
        if (size() == 1) T.removeLast();
        else {
            T.swap(T.root(), T.last());
            T.removeLast();
            Position u = T.root();
            while (2 * T.idx(u) <= T.size()) { // while hasLeft
                Position v = T.pos(2 * T.idx(u)); // left child
                if (2 * T.idx(u) + 1 <= T.size()) { // if hasRight
                    Position w = T.pos(2 * T.idx(u) + 1);
                    if (isLess(*w, *v)) v = w; // pick smaller child
                }
                if (isLess(*v, *u)) {
                    T.swap(u, v);
                    u = v;
                } else break;
            }
        }
    }

    

private:
    VectorCompleteTree<E> T;
    C isLess;
    typedef typename VectorCompleteTree<E>::Position Position;
};

// =============================================================================
// 8.3.4 HEAP-SORT & OPTIMIZATIONS
// =============================================================================
/*
 * 1. Heap-Sort: Phase 1 (n log n) + Phase 2 (n log n) = Total O(n log n).
 * 2. In-Place Heap-Sort: Uses the input array itself as the heap to achieve 
 * O(1) extra space.
 * 3. Bottom-Up Construction: If all n elements are known at start, we can 
 * build the heap in O(n) time by "heapifying" from the leaves up.
 */




// =============================================================================
// PERFORMANCE SUMMARY
// =============================================================================
/*
 * | Operation | Time Complexity |
 * |-----------|-----------------|
 * | size      | O(1)            |
 * | min       | O(1)            |
 * | insert    | O(log n)        |
 * | removeMin | O(log n)        |
 */
