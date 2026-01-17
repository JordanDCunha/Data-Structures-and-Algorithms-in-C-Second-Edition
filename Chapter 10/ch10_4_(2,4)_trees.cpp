/**
 * CHAPTER 10.4: (2,4) TREES
 * --- THE CONCEPT ---
 * A (2,4) Tree (also known as a 2-3-4 tree) is a BALANCED MULTI-WAY SEARCH TREE.
 * Unlike binary trees, each internal node can store multiple keys and have 
 * multiple children.
 * * Key Properties:
 * 1. Size Property: Every internal node has at least 2 and at most 4 children.
 * 2. Depth Property: All external nodes (leaves) have the exact same depth.
 */

#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 10.4.1 MULTI-WAY SEARCH TREES
// =============================================================================
/*
 * In a d-node (a node with d children), we store d-1 sorted keys: k1, k2, ..., kd-1.
 * These keys act as "barriers" for searching:
 * - Child 1: keys < k1
 * - Child 2: k1 < keys < k2
 * - Child d: keys > kd-1
 */



// =============================================================================
// 10.4.2 SEARCH AND INSERTION
// =============================================================================
/**
 * SEARCH: Similar to BST but with more choices at each node. 
 * Since d is small (max 4), searching inside a node is O(1).
 * Total search time: O(log n).
 * * INSERTION:
 * 1. Search for the key and insert it into a leaf-parent node.
 * 2. If the node now has 5 children (OVERFLOW), we must SPLIT it.
 */



/**
 * SPLIT OPERATION:
 * - The 5-node is split into a 3-node and a 2-node.
 * - The "middle" key is promoted to the parent node.
 * - This may cause a "cascading split" up to the root.
 */

// =============================================================================
// 10.4.3 REMOVAL
// =============================================================================
/**
 * REMOVAL:
 * 1. If the key is in an internal node, swap it with its inorder successor.
 * 2. Remove the key from the leaf-level node.
 * 3. If the node now has < 2 children (UNDERFLOW), we perform:
 * - TRANSFER: "Borrow" a key from a sibling (if the sibling has > 2 children).
 * - FUSION: Merge the node with a sibling if both are 2-nodes.
 */



// =============================================================================
// 10.4.4 PERFORMANCE SUMMARY
// =============================================================================
/**
 * | Operation | Time Complexity | Reason |
 * |-----------|-----------------|--------|
 * | find      | O(log n)        | Height is always logarithmic. |
 * | insert    | O(log n)        | Max O(log n) splits. |
 * | erase     | O(log n)        | Max O(log n) fusions. |
 * * Space Usage: O(n)
 */

/**
 * NEXT STEP:
 * (2,4) trees are structurally elegant but can be complex to implement 
 * due to multiple node types. Would you like to see Section 10.5: Red-Black Trees, 
 * which represent (2,4) trees as colored binary trees?
 */
