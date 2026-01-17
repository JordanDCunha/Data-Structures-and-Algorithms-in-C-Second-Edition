/**
 * CHAPTER 11.6: SETS AND UNION/FIND STRUCTURES
 * --- OVERVIEW ---
 * This file covers the Set ADT, Mergable Sets via the Template Method Pattern, 
 * and Partition (Union-Find) structures using sequence and tree-based approaches.
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// 11.6.1: THE MERGE TEMPLATE METHOD PATTERN
// =============================================================================
/**
 * The Merge class implements a "Template Method" pattern. 
 * The logic for traversing two sorted lists is fixed in merge(), 
 * but the behavior for specific set operations (Union, Intersect, Subtract)
 * is deferred to subclasses.
 */
template <typename E>
class Merge {
public:
    typedef std::list<E> List;
    typedef typename List::iterator Itor;

    // The Template Method: Fixed skeleton of the algorithm
    void merge(List& A, List& B, List& C) {
        Itor pa = A.begin();
        Itor pb = B.begin();
        while (pa != A.end() && pb != B.end()) {
            if (*pa < *pb)
                fromA(*pa++, C);
            else if (*pa == *pb)
                fromBoth(*pa++, *pb++, C);
            else
                fromB(*pb++, C);
        }
        while (pa != A.end()) fromA(*pa++, C);
        while (pb != B.end()) fromB(*pb++, C);
    }

protected:
    // Hooks to be overridden by subclasses
    virtual void fromA(const E& a, List& C) = 0;
    virtual void fromBoth(const E& a, const E& b, List& C) = 0;
    virtual void fromB(const E& b, List& C) = 0;
};

// --- Subclass Specializations ---

template <typename E>
class UnionMerge : public Merge<E> {
protected:
    void fromA(const E& a, typename Merge<E>::List& C) override { C.push_back(a); }
    void fromBoth(const E& a, const E& b, typename Merge<E>::List& C) override { C.push_back(a); }
    void fromB(const E& b, typename Merge<E>::List& C) override { C.push_back(b); }
};

template <typename E>
class IntersectMerge : public Merge<E> {
protected:
    void fromA(const E& a, typename Merge<E>::List& C) override {} // Ignore
    void fromBoth(const E& a, const E& b, typename Merge<E>::List& C) override { C.push_back(a); }
    void fromB(const E& b, typename Merge<E>::List& C) override {} // Ignore
};

// =============================================================================
// 11.6.2: PARTITIONS (UNION-FIND) - TREE-BASED
// =============================================================================
/**
 * A Partition stores disjoint sets. 
 * Optimized with Union-by-Size and Path Compression.
 */
struct Node {
    int element;
    int parent; // Index of parent node
    int size;   // Subtree size for Union-by-Size
    Node(int e, int i) : element(e), parent(i), size(1) {}
};

class Partition {
private:
    vector<Node> nodes;

public:
    int makeSet(int x) {
        int id = nodes.size();
        nodes.push_back(Node(x, id)); // Initially, root of itself
        return id;
    }

    /**
     * find(p) with Path Compression:
     * As we search for the root, we point all visited nodes directly to the root.
     */
    int find(int p) {
        if (nodes[p].parent == p)
            return p;
        // Path Compression step
        return nodes[p].parent = find(nodes[p].parent);
    }

    

    /**
     * union(p, q) with Union-by-Size:
     * Attach the smaller tree to the root of the larger tree.
     */
    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP != rootQ) {
            if (nodes[rootP].size < nodes[rootQ].size) {
                nodes[rootP].parent = rootQ;
                nodes[rootQ].size += nodes[rootP].size;
            } else {
                nodes[rootQ].parent = rootP;
                nodes[rootP].size += nodes[rootQ].size;
            }
        }
    }

    
};

// =============================================================================
// PERFORMANCE SUMMARY
// =============================================================================
/**
 * 1. Sequence-based Partition:
 * - find: O(1)
 * - union: O(n log n) total for n operations (amortized O(log n))
 * * 2. Tree-based Partition (with Union-by-Size + Path Compression):
 * - Amortized time per operation: O(α(n)), where α is the inverse Ackermann function.
 * - For all practical purposes (n < 2^65536), α(n) <= 5.
 * - This is nearly constant time.
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a specific example of an Internet Search Engine query using IntersectMerge?
 * 2. Show the detailed derivation of why the log-star function (log* n) appears?
 * 3. Provide the full SubtractMerge implementation?
 */
