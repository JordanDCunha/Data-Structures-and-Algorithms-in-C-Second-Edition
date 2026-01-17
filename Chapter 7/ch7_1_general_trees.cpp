/**
 * CHAPTER 7.1: GENERAL TREES
 * --- THE CONCEPT ---
 * Trees are nonlinear data structures that represent hierarchical relationships.
 * Unlike lists (before/after), trees use parent-child relationships (above/below).
 */

#include <iostream>
#include <list>
#include <string>

using namespace std;

// =============================================================================
// 7.1.1 TERMINOLOGY & DEFINITIONS
// =============================================================================
/*
 * Root:     The top node (no parent).
 * Internal: Node with 1+ children.
 * External: Node with 0 children (also called a Leaf).
 * Ancestors: Parent, Grandparent, etc.
 * Descendants: Children, Grandchildren, etc.
 * Subtree:  A tree consisting of a node and all its descendants.
 */



// =============================================================================
// 7.1.2 TREE INTERFACES (Informal)
// =============================================================================

// Forward declaration of Position
template <typename E> class Position;

/**
 * Position ADT: Abstracts the notion of a "node" in the tree.
 */
template <typename E>
class Position {
public:
    E& operator*();                    // Access element
    Position parent() const;           // Get parent position
    list<Position> children() const;   // Get list of children positions
    bool isRoot() const;               // Check if root
    bool isExternal() const;           // Check if leaf
};

/**
 * Tree ADT: The container interface.
 */
template <typename E>
class Tree {
public:
    // We assume Position is defined within or associated with Tree
    typedef Position<E> Pos; 

    int size() const;                  // Number of nodes
    bool empty() const;                // Is tree empty?
    Pos root() const;                  // Get root position
    list<Pos> positions() const;       // List of all nodes (for traversal)
};

// =============================================================================
// 7.1.3 LINKED STRUCTURE FOR GENERAL TREES
// =============================================================================
/*
 * Each Node in a general tree linked structure typically contains:
 * 1. The Element (Data)
 * 2. Pointer to the Parent
 * 3. A List/Container of pointers to Children
 */



// Example of how a Directory Tree might look in memory:
/*
 * [ / (root) ]
 * |
 * +-- [ bin/ ]
 * |     |
 * |     +-- [ ls ]
 * |     +-- [ cp ]
 * |
 * +-- [ home/ ]
 * |
 * +-- [ user/ ]
 */

// =============================================================================
// 7.1.4 PERFORMANCE SUMMARY
// =============================================================================
/*
 * Operation      | Time Complexity
 * ----------------|----------------
 * size, empty     | O(1)
 * root, parent    | O(1)
 * isRoot, isExt   | O(1)
 * children(p)     | O(number of children)
 * positions       | O(n)
 *
 * Space Usage     | O(n)
 */

int main() {
    cout << "Tree ADT Infrastructure Loaded." << endl;
    cout << "Common applications include:" << endl;
    cout << "1. File Systems (Folders/Files)" << endl;
    cout << "2. Organizational Charts" << endl;
    cout << "3. HTML/XML DOM structures" << endl;
    
    return 0;
}
