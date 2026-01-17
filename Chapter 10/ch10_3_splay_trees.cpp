/**
 * CHAPTER 10.3: SPLAY TREES
 * --- THE CONCEPT ---
 * A Splay Tree is a self-adjusting Binary Search Tree. Unlike AVL or Red-Black 
 * trees, it does not store extra height or color information. Instead, it 
 * uses a "move-to-root" operation called SPLAYING.
 * * Key Idea: Whenever a node is accessed (search, insert, or delete), it is 
 * moved to the root. This improves performance for frequently accessed items.
 */

#include <iostream>

using namespace std;

// =============================================================================
// 10.3.1 THE SPLAYING OPERATION
// =============================================================================
/*
 * Splaying moves a node x to the root through three types of double or single 
 * rotations, depending on the positions of x, its parent y, and grandparent z.
 */

/**
 * CASE 1: ZIG-ZIG (x and y are both left/right children)
 * Result: The tree is "flattened," reducing the depth of all nodes on the path.
 */


/**
 * CASE 2: ZIG-ZAG (x is a left child, y is a right child, or vice versa)
 * Result: Similar to a double rotation in an AVL tree.
 */


/**
 * CASE 3: ZIG (x has a parent but no grandparent)
 * Result: A single rotation to bring x to the root.
 */


// =============================================================================
// 10.3.2 WHEN TO SPLAY
// =============================================================================
/*
 * - SEARCH: Splay the node where the key is found, or the last internal node 
 * visited if the search fails.
 * - INSERT: Splay the newly inserted node.
 * - DELETE: Splay the parent of the node that was physically removed from the tree.
 */



// =============================================================================
// 10.3.3 PERFORMANCE ANALYSIS (AMORTIZED)
// =============================================================================
/**
 * While a single operation can take O(n) in a skewed tree, a sequence of m 
 * operations is guaranteed to take O(m log n) time.
 * * --- AMORTIZED VS. WORST-CASE ---
 * | Operation | Worst-Case | Amortized  |
 * |-----------|------------|------------|
 * | Search    | O(n)       | O(log n)   |
 * | Insert    | O(n)       | O(log n)   |
 * | Delete    | O(n)       | O(log n)   |
 */

/*
 * THE POTENTIAL FUNCTION (Accounting Method):
 * We define Rank r(v) = log(size(v)), where size(v) is the number of nodes 
 * in v's subtree. Splaying "pays" for itself by decreasing the total rank 
 * sum of the tree during zig-zig operations.
 */

// =============================================================================
// 10.3.4 SPECIAL PROPERTIES
// =============================================================================
/**
 * STATIC OPTIMALITY:
 * Splay trees are as fast as an optimal static binary search tree. If an 
 * entry is accessed with frequency f(i), the amortized cost to access it 
 * is O(log(m / f(i))). This means frequently used items stay near the root.
 */

/**
 * NEXT STEP:
 * Splay trees are great for "locality of reference." Would you like to see 
 * Section 10.4: (2,4) Trees, which take a multi-way approach to balancing?
 */
