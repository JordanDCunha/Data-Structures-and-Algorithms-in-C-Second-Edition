/**
 * CHAPTER 10 EXERCISES: SEARCH TREE REINFORCEMENT
 * --- OVERVIEW ---
 * This file contains logic, solutions, and algorithmic descriptions for selected 
 * Reinforcement and Creativity exercises from Chapter 10.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// =============================================================================
// REINFORCEMENT SOLUTIONS (Conceptual & Logical)
// =============================================================================

/**
 * R-10.1: Sequential Insertion into BST
 * Keys: (1,A), (2,B), (3,C), (4,D), (5,E)
 * Result: A degenerate "right-skewed" tree (essentially a linked list).
 * 1
 * \
 * 2
 * \
 * 3
 * \
 * 4
 * \
 * 5
 */

/**
 * R-10.5: Jack's Claim (Order doesn't matter in BST)
 * Counter-example:
 * Set = {1, 2, 3}
 * Order [2, 1, 3] -> Root is 2, 1 is left child, 3 is right child (Balanced).
 * Order [1, 2, 3] -> Root is 1, 2 is right child, 3 is 2's right child (Skewed).
 * Conclusion: Jack is wrong; insertion order determines the root and overall shape.
 */

/**
 * R-10.19: Worst-case Height of T with 100,000 entries
 * 1. AVL Tree: O(log n) -> ~1.44 * log2(100,000) ≈ 24 levels.
 * 2. (2,4) Tree: O(log n) -> log2(100,000) ≈ 17 levels.
 * 3. Red-Black Tree: O(log n) -> 2 * log2(100,001) ≈ 34 levels.
 * 4. Splay Tree: O(n) -> 100,000 (if accessed sequentially).
 * 5. BST: O(n) -> 100,000 (if inserted sequentially).
 */

// =============================================================================
// CREATIVITY SOLUTIONS (Algorithmic Logic)
// =============================================================================

/**
 * C-10.1: Finding the Median Entry in O(h)
 * Logic: Augment each node with a 'size' field (number of nodes in its subtree).
 * 1. Let k = (n+1)/2.
 * 2. At node v:
 * - If size(left_child) == k-1, v is the median.
 * - If size(left_child) >= k, search left with rank k.
 * - If size(left_child) < k-1, search right with rank k - size(left_child) - 1.
 */



/**
 * C-10.22: Half-Splay Trees
 * A half-splay tree reduces the number of rotations by stopping the splay 
 * operation when the node reaches half its original depth. This still 
 * provides amortized efficiency while reducing the "churn" of the tree 
 * structure for deep nodes.
 */

// =============================================================================
// P-10.4: AVL TREE MAP IMPLEMENTATION (SKELETON)
// =============================================================================

template <typename K, typename V>
struct Node {
    K key;
    V value;
    int height;
    Node *left, *right;
    Node(K k, V v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

template <typename K, typename V>
class AVLMap {
private:
    Node<K, V>* root;

    int getHeight(Node<K, V>* n) { return n ? n->height : 0; }
    int getBalance(Node<K, V>* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

    Node<K, V>* rotateRight(Node<K, V>* y) {
        Node<K, V>* x = y->left;
        Node<K, V>* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    Node<K, V>* rotateLeft(Node<K, V>* x) {
        Node<K, V>* y = x->right;
        Node<K, V>* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    

public:
    AVLMap() : root(nullptr) {}
    
    void put(K key, V value) {
        // Implementation of AVL insertion logic with rotations...
    }

    V get(K key) {
        // Standard BST search...
        return V();
    }
};

/**
 * FINAL SUMMARY OF CHAPTER 10:
 * - BST: Basic structure, can become O(n).
 * - AVL: Strictly balanced using height, O(log n) worst case.
 * - Red-Black: Balanced using colors, O(log n), fewer rotations than AVL.
 * - (2,4) Trees: Multi-way search trees, foundation for Red-Black logic.
 * - Splay Trees: Heuristic-based, O(log n) amortized, moves active nodes to root.
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Provide the full C++ implementation for the "Jumping Leprechauns" simulation (P-10.1)?
 * 2. Show the step-by-step drawing for the R-10.16 Red-Black tree insertion?
 * 3. Explain the O(n) rotation proof for C-10.8?
 */
