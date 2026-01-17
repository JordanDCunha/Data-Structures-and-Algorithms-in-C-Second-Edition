/**
 * CHAPTER 14.3: EXTERNAL SEARCHING AND B-TREES
 * --- THE PROBLEM OF I/O COMPLEXITY ---
 * Disk accesses are ~1,000,000x slower than RAM.
 * Standard Binary Search Trees (AVL, Red-Black) have O(log2 n) height.
 * In external memory, this means O(log2 n) disk transfers, which is too slow.
 * * --- THE SOLUTION: (a,b) TREES & B-TREES ---
 * By increasing the branching factor (the number of children per node), 
 * we drastically reduce the height of the tree.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// 14.5.1: (a,b) TREE DEFINITION
// =============================================================================
/**
 * An (a,b) tree is a multi-way search tree where:
 * 1. Size: Internal nodes have [a, b] children (root has [2, b]).
 * 2. Depth: All external (leaf) nodes are at the same depth.
 * 3. Constraint: 2 <= a <= (b + 1) / 2.
 */



// =============================================================================
// 14.5.2: B-TREES
// =============================================================================
/**
 * A B-Tree of order 'd' is an (a,b) tree where:
 * a = ceil(d/2) and b = d.
 * * * OPTIMIZATION FOR DISK:
 * We choose 'd' so that one node (containing d-1 keys and d pointers) 
 * fits exactly into one disk block (Page).
 * This makes f(b) = 1 disk transfer.
 */



// =============================================================================
// 14.5.3: B-TREE OPERATIONS (I/O Complexity)
// =============================================================================
/**
 * HEIGHT ANALYSIS:
 * The height 'h' of a B-Tree is O(log_a n). Since 'a' is proportional 
 * to the block size 'B', the height is O(log_B n).
 * * | Operation | I/O Complexity (Disk Transfers) |
 * |-----------|--------------------------------|
 * | Search    | O(log_B n)                     |
 * | Insert    | O(log_B n)                     |
 * | Remove    | O(log_B n)                     |
 */

// Example: Schematic Logic for B-Tree Insertion (Split)
/**
 * When a node exceeds 'b-1' keys:
 * 1. Split the node into two.
 * 2. Move the median key up to the parent.
 * 3. If parent overflows, repeat (rippling up).
 */



// =============================================================================
// COMPARISON OF SEARCH TIMES
// =============================================================================
/**
 * For n = 1,000,000,000 and Block size B = 1,000:
 * - Binary Tree: log2(10^9) ≈ 30 disk transfers.
 * - B-Tree: log1000(10^9) = 3 disk transfers.
 * * The B-tree reduces disk I/O by a factor of 10 in this scenario.
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Provide the C++ code for a B-Tree 'Split' and 'Transfer' logic?
 * 2. Explain the difference between B-Trees and B+ Trees (used in modern filesystems)?
 * 3. Discuss how B-Trees are used specifically in SQL databases for indexing?
 */
