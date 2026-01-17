/**
 * CHAPTER 7 EXERCISES: SOLUTIONS AND ALGORITHMS
 * --------------------------------------------
 * This file contains logic for Reinforcement (R) and Creativity (C) exercises.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Assuming the LinkedBinaryTree structure from previous sections
#include "LinkedBinaryTree.h" 

// =============================================================================
// REINFORCEMENT EXERCISES
// =============================================================================

/**
 * R-7.1: Count left external nodes.
 * Logic: Perform a traversal; if a node has a left child and that child 
 * is external, increment count.
 */
int countLeftExternal(const LinkedBinaryTree& T, const LinkedBinaryTree::Position& p) {
    if (p.isExternal()) return 0;
    int count = 0;
    LinkedBinaryTree::Position left = p.left();
    if (left.isExternal()) count = 1;
    else count = countLeftExternal(T, left);
    
    count += countLeftExternal(T, p.right());
    return count;
}

/**
 * R-7.18: Preorder printing with indentation.
 * Useful for visualizing directory structures.
 */
void indentedPreorderPrint(const Tree& T, const Position& p, int depth) {
    for (int i = 0; i < depth; ++i) cout << "  "; // Indent
    cout << *p << endl;
    PositionList ch = p.children();
    for (auto q = ch.begin(); q != ch.end(); ++q) {
        indentedPreorderPrint(T, *q, depth + 1);
    }
}

// =============================================================================
// CREATIVITY EXERCISES
// =============================================================================

/**
 * C-7.6: O(n) Algorithm for depth of all nodes.
 * Logic: Pass the depth down during a preorder traversal.
 */
void computeAllDepths(const Tree& T, const Position& p, int d, vector<int>& depths) {
    // Assuming depths is pre-allocated and node has some index mapping
    // depths[index(p)] = d; 
    
    PositionList ch = p.children();
    for (auto q = ch.begin(); q != ch.end(); ++q) {
        computeAllDepths(T, *q, d + 1, depths);
    }
}

/**
 * C-7.26: LCA in Vector-based Binary Tree.
 * Logic: In level-numbering f(v), the parent is f(v)/2.
 * To find LCA of v and w, keep dividing the larger index by 2 
 * until the indices match.
 */
int findLCALevelNumber(int fv, int fw) {
    while (fv != fw) {
        if (fv > fw) fv /= 2;
        else fw /= 2;
    }
    return fv;
}

/**
 * C-7.34: Level-Order Traversal (BFS).
 * Logic: Use a queue to visit nodes level by level.
 */
#include <queue>
void levelOrderTraversal(const LinkedBinaryTree& T) {
    if (T.empty()) return;
    queue<LinkedBinaryTree::Position> q;
    q.push(T.root());
    
    while (!q.empty()) {
        LinkedBinaryTree::Position curr = q.front();
        q.pop();
        
        cout << *curr << " "; // Visit
        
        if (!curr.left().isNull()) q.push(curr.left());
        if (!curr.right().isNull()) q.push(curr.right());
    }
}

// =============================================================================
// CONCEPTUAL SOLUTIONS (Comments)
// =============================================================================

/*
 * R-7.12: Preorder vs Postorder
 * - Can they be the same? Only if the tree has exactly one node. If there 
 * are >1 nodes, the root is first in preorder and last in postorder.
 * - Can they be the reverse? Yes, in a "linear" tree (each node has only 
 * one child).
 *
 * R-7.16: Binary Tree Properties
 * - Min external nodes (height h): 1 (a path of internal nodes ending in one leaf).
 * Note: If proper, min is h + 1.
 * - Max external nodes (height h): 2^h.
 *
 * C-7.9: Proper 3-way tree property.
 * If every internal node has 3 children:
 * Total nodes n = nI + nE.
 * Total edges = n - 1. 
 * Also, total edges = 3 * nI (each internal node provides 3 edges to children).
 * nI + nE - 1 = 3 * nI  =>  nE = 2 * nI + 1.
 */

int main() {
    cout << "Tree Exercise Library Loaded." << endl;
    return 0;
}
