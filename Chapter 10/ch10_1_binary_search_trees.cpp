/**
 * CHAPTER 10.1: BINARY SEARCH TREES
 * --- THE CONCEPT ---
 * A Binary Search Tree (BST) is a hierarchical data structure where:
 * - Each internal node stores a key-value entry.
 * - Left Subtree: Contains keys less than or equal to the parent's key.
 * - Right Subtree: Contains keys greater than or equal to the parent's key.
 * - Inorder Traversal: Visiting nodes in order (Left, Root, Right) yields 
 * keys in non-decreasing order.
 */

#include <iostream>
#include <exception>

using namespace std;

// =============================================================================
// 10.1.1 SEARCHING IN A BST
// =============================================================================
/*
 * Searching follows a path from the root down. At each node, we decide 
 * to go left or right based on a comparison.
 * Time Complexity: O(h), where h is the height of the tree.
 */



// =============================================================================
// 10.1.2 UPDATES: INSERTION AND REMOVAL
// =============================================================================
/**
 * INSERTION:
 * 1. Search for the key k.
 * 2. When an external node (placeholder) is reached, replace it with a 
 * new internal node containing (k, v).
 * * REMOVAL:
 * - Case 1: Node has an external child. Simply "bypass" the node.
 * - Case 2: Node has two internal children. Replace the node's entry with 
 * its inorder successor, then remove the successor node.
 */



// =============================================================================
// 10.1.3 BST IMPLEMENTATION STRUCTURE
// =============================================================================

template <typename E>
class SearchTree {
public:
    typedef typename E::Key K;
    typedef typename E::Value V;

    // Iterator class to navigate the tree in order
    class Iterator {
    private:
        // TPos v; // Position in the underlying tree (Conceptual)
    public:
        // Moves to the inorder successor
        Iterator& operator++() {
            /* Logic: If right child exists, go right then leftmost.
               Else, go up until we are no longer a right child. */
            return *this;
        }
    };

    /**
     * SEARCH UTILITY (Recursive)
     * finder(k, v):
     * - If v is external, return v (not found).
     * - If k < v.key, return finder(k, v.left).
     * - If k > v.key, return finder(k, v.right).
     * - Else, return v (found).
     */

    // ... Implementation of find(), insert(), and erase() ...
};

// =============================================================================
// 10.1.4 PERFORMANCE SUMMARY
// =============================================================================
/**
 * | Operation | Average Time | Worst Case Time |
 * |-----------|--------------|-----------------|
 * | find      | O(log n)     | O(n)            |
 * | insert    | O(log n)     | O(n)            |
 * | erase     | O(log n)     | O(n)            |
 * * Space Usage: O(n)
 * * Note: Worst case O(n) occurs when the tree is "skewed" (looks like a list).
 */



/**
 * NEXT STEP:
 * Standard BSTs
