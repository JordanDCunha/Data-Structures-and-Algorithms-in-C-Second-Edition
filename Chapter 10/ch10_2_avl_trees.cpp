/**
 * CHAPTER 10.2: AVL TREES
 * --- THE CONCEPT ---
 * An AVL tree is a self-balancing Binary Search Tree (BST) where the heights 
 * of the two child subtrees of any node differ by at most one.
 * * * Height-Balance Property: For every internal node v, |height(left(v)) - height(right(v))| <= 1.
 * * This property ensures that the tree height h is O(log n), providing 
 * guaranteed O(log n) performance for search, insertion, and removal.
 */

#include <iostream>
#include <algorithm>

using namespace std;

// =============================================================================
// 10.2.1 DATA STRUCTURES FOR AVL NODES
// =============================================================================

/**
 * AVLEntry: Extends the basic Entry to store height information.
 */
template <typename E>
class AVLEntry : public E {
private:
    int ht; // The height of the node
protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
    int height() const { return ht; }
    void setHeight(int h) { ht = h; }
public:
    AVLEntry(const K& k = K(), const V& v = V()) : E(k, v), ht(0) { }
    // Friend class allows AVLTree to access protected height methods
    template <typename T> friend class AVLTree;
};

// =============================================================================
// 10.2.2 AVL TREE IMPLEMENTATION
// =============================================================================

template <typename E>
class AVLTree : public SearchTree< AVLEntry<E> > {
public:
    typedef AVLEntry<E> Entry;
    typedef typename SearchTree<Entry>::Iterator Iterator;
protected:
    typedef typename Entry::Key K;
    typedef typename Entry::Value V;
    typedef SearchTree<Entry> ST;
    typedef typename ST::TPos TPos;

public:
    AVLTree() : ST() { }

    /**
     * INSERTION: O(log n)
     * Performs standard BST insertion and then rebalances the path to the root.
     */
    Iterator insert(const K& k, const V& x) {
        TPos v = this->inserter(k, x); // Standard BST insertion
        setHeight(v);
        rebalance(v); // Restore AVL property
        return Iterator(v);
    }

    /**
     * REMOVAL: O(log n)
     * Performs standard BST removal and rebalances the path to the root.
     */
    void erase(const K& k) {
        TPos v = this->finder(k, this->root());
        if (Iterator(v) == this->end()) throw "NonexistentElement";
        TPos w = this->eraser(v); // Standard BST removal
        rebalance(w);
    }

protected:
    // Utility for node height (external nodes have height 0)
    int height(const TPos& v) const { 
        return (v.isExternal() ? 0 : v->height()); 
    }

    // Updates a node's height based on its children
    void setHeight(TPos v) {
        int hl = height(v.left());
        int hr = height(v.right());
        v->setHeight(1 + std::max(hl, hr));
    }

    // Checks the height-balance property
    bool isBalanced(const TPos& v) const {
        int bal = height(v.left()) - height(v.right());
        return (bal >= -1 && bal <= 1);
    }

    // Identifies the tallest grandchild for trinode restructuring
    TPos tallGrandchild(const TPos& z) const {
        TPos zl = z.left();
        TPos zr = z.right();
        if (height(zl) >= height(zr))
            return (height(zl.left()) >= height(zl.right()) ? zl.left() : zl.right());
        else
            return (height(zr.right()) >= height(zr.left()) ? zr.right() : zr.left());
    }

    /**
     * REBALANCE: O(log n)
     * Traverses upward from node v, performing trinode restructurings (rotations)
     * whenever an imbalance is found.
     */
    
    void rebalance(const TPos& v) {
        TPos z = v;
        while (!(z == this->root())) {
            z = z.parent();
            setHeight(z);
            if (!isBalanced(z)) {
                TPos x = tallGrandchild(z);
                z = this->restructure(x); // Perform rotation
                setHeight(z.left());
                setHeight(z.right());
                setHeight(z);
            }
        }
    }
};

// =============================================================================
// 10.2.3 PERFORMANCE SUMMARY
// =============================================================================
/**
 * | Operation | Time Complexity | Note |
 * |-----------|-----------------|------|
 * | find      | O(log n)        | Tree height is guaranteed logarithmic. |
 * | insert    | O(log n)        | Requires at most one restructuring. |
 * | erase     | O(log n)        | May require O(log n) restructurings. |
 */

/**
 * NEXT STEP:
 * AVL trees are strictly balanced. Would you like to explore Section 10.3: Splay Trees, 
 * which use a different "move-to-root" heuristic to achieve amortized balance?
 */
