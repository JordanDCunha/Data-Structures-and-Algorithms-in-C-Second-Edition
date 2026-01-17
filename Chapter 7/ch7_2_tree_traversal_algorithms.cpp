/**
 * CHAPTER 7.2: TREE TRAVERSAL ALGORITHMS
 * --- THE CONCEPT ---
 * Traversals are systematic ways of visiting every node in a tree.
 * 1. Depth: How far a node is from the root.
 * 2. Height: How far a node is from its furthest leaf.
 * 3. Preorder: Visit root, then children (Top-Down).
 * 4. Postorder: Visit children, then root (Bottom-Up).
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

// =============================================================================
// 7.2.1 DEPTH AND HEIGHT
// =============================================================================

/**
 * Depth: Number of ancestors (Root = 0).
 * Time Complexity: O(depth of p), Worst Case O(n).
 */
int depth(const Tree& T, const Position& p) {
    if (p.isRoot()) return 0;
    return 1 + depth(T, p.parent());
}



/**
 * Height: 1 + max height of children (Leaf = 0).
 * Time Complexity: O(n) as it visits every node in the subtree once.
 */
int height2(const Tree& T, const Position& p) {
    if (p.isExternal()) return 0;
    int h = 0;
    PositionList ch = p.children();
    for (auto q = ch.begin(); q != ch.end(); ++q)
        h = max(h, height2(T, *q));
    return 1 + h;
}



// =============================================================================
// 7.2.2 PREORDER TRAVERSAL (Top-Down)
// =============================================================================
/* Use Case: Table of Contents, Directory listing where parent precedes contents. */

void preorderPrint(const Tree& T, const Position& p) {
    cout << *p << " ";                 // "Visit" action happens FIRST
    PositionList ch = p.children();
    for (auto q = ch.begin(); q != ch.end(); ++q) {
        preorderPrint(T, *q);
    }
}

/**
 * Parenthetic Representation: Useful for visualizing tree structure in text.
 * Format: Root ( Child1 Child2 ... )
 */
void parenPrint(const Tree& T, const Position& p) {
    cout << *p;
    if (!p.isExternal()) {
        PositionList ch = p.children();
        cout << "( ";
        for (auto q = ch.begin(); q != ch.end(); ++q) {
            if (q != ch.begin()) cout << " ";
            parenPrint(T, *q);
        }
        cout << " )";
    }
}



// =============================================================================
// 7.2.3 POSTORDER TRAVERSAL (Bottom-Up)
// =============================================================================
/* Use Case: Calculating folder sizes, deleting a tree (must delete children first). */

void postorderPrint(const Tree& T, const Position& p) {
    PositionList ch = p.children();
    for (auto q = ch.begin(); q != ch.end(); ++q) {
        postorderPrint(T, *q);
    }
    cout << *p << " ";                 // "Visit" action happens LAST
}

/**
 * Example: Disk Space Calculation
 * We can't know the size of a directory until we sum its sub-directories.
 */
int diskSpace(const Tree& T, const Position& p) {
    int s = size(p);                   // Metadata size of node p
    if (!p.isExternal()) {
        PositionList ch = p.children();
        for (auto q = ch.begin(); q != ch.end(); ++q)
            s += diskSpace(T, *q);     // Add recursive size of subtrees
        cout << name(p) << ": " << s << endl;
    }
    return s;
}



// =============================================================================
// SUMMARY OF TRAVERSALS
// =============================================================================
/*
 * TRAVERSAL  | VISIT ORDER          | TYPICAL USE
 * -----------|----------------------|-----------------------------------------
 * Preorder   | Node, then Children  | Hierarchical listing (Table of Contents)
 * Postorder  | Children, then Node  | Space summation, expression evaluation
 * Breadth-1st| Level by Level       | Game AI (searching moves), Networking
 */
