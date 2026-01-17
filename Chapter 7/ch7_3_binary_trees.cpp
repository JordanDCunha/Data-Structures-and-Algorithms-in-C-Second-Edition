/**
 * CHAPTER 7.3: BINARY TREES
 * --- THE CONCEPT ---
 * A Binary Tree is a specialized tree where each node has AT MOST two children,
 * specifically designated as the "Left Child" and the "Right Child".
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// =============================================================================
// 7.3.1 PROPERTIES OF BINARY TREES
// =============================================================================
/*
 * 1. Proper (Full): Every node has either 0 or 2 children.
 * 2. Level d: Max nodes at level d = 2^d.
 * 3. Height h vs Nodes n: 
 * - h + 1 <= n <= 2^(h+1) - 1
 * - log(n+1) - 1 <= h <= n - 1
 * 4. Proper Tree Relation: External nodes (nE) = Internal nodes (nI) + 1.
 */



// =============================================================================
// 7.3.2 LINKED STRUCTURE IMPLEMENTATION
// =============================================================================

typedef int Elem;

struct Node {
    Elem elt;
    Node* par;
    Node* left;
    Node* right;
    Node() : elt(), par(NULL), left(NULL), right(NULL) {}
};

class LinkedBinaryTree {
public:
    class Position {
    private:
        Node* v;
    public:
        Position(Node* _v = NULL) : v(_v) {}
        Elem& operator*() { return v->elt; }
        Position left() const { return Position(v->left); }
        Position right() const { return Position(v->right); }
        Position parent() const { return Position(v->par); }
        bool isRoot() const { return v->par == NULL; }
        bool isExternal() const { return v->left == NULL && v->right == NULL; }
        friend class LinkedBinaryTree;
    };

    typedef std::list<Position> PositionList;

public:
    LinkedBinaryTree() : _root(NULL), n(0) {}
    int size() const { return n; }
    bool empty() const { return n == 0; }
    Position root() const { return Position(_root); }

    // Update Functions
    void addRoot() { _root = new Node; n = 1; }
    
    // Transform external node into internal by adding two children
    void expandExternal(const Position& p) {
        Node* v = p.v;
        v->left = new Node; v->left->par = v;
        v->right = new Node; v->right->par = v;
        n += 2;
    }

private:
    Node* _root;
    int n;
};

// =============================================================================
// 7.3.3 VECTOR-BASED (ARRAY) REPRESENTATION
// =============================================================================
/*
 * For a node at index i:
 * - Left Child:  2 * i
 * - Right Child: 2 * i + 1
 * - Parent:      floor(i / 2)
 * Note: Space can be O(2^n) if the tree is unbalanced (sparse array).
 */



// =============================================================================
// 7.3.4 BINARY TREE TRAVERSALS
// =============================================================================

/**
 * INORDER TRAVERSAL: Left Subtree -> Root -> Right Subtree
 * Result: Visited "Left to Right".
 * Use Case: Printing Binary Search Trees (BST) in sorted order.
 */
void inorderPrint(const LinkedBinaryTree::Position& p) {
    if (!p.isExternal()) inorderPrint(p.left());
    cout << *p << " ";
    if (!p.isExternal()) inorderPrint(p.right());
}

/**
 * EVALUATE EXPRESSION: Uses Postorder (Left, Right, Root)
 */
int evaluateExpression(const LinkedBinaryTree::Position& p) {
    if (p.isExternal()) return *p; // Assume leaf stores operand
    int x = evaluateExpression(p.left());
    int y = evaluateExpression(p.right());
    // Assume *p stores an operator code
    char op = (char)*p; 
    if (op == '+') return x + y;
    if (op == '*') return x * y;
    return 0;
}



// =============================================================================
// 7.3.5 BINARY SEARCH TREES (BST)
// =============================================================================
/*
 * Definition:
 * - Left descendants <= Parent
 * - Right descendants >= Parent
 * Search Time: O(h), where h is height.
 */
