/**
 * CHAPTER 10.5: RED-BLACK TREES
 * --- THE CONCEPT ---
 * A Red-Black Tree is a Binary Search Tree that mimics the behavior of a (2,4) tree.
 * It uses node coloring to ensure the tree remains balanced.
 * * --- PROPERTIES ---
 * 1. Root Property: The root is always Black.
 * 2. External Property: Every external node (leaf) is Black.
 * 3. Internal Property: The children of a Red node must be Black (no "double red").
 * 4. Depth Property: All external nodes have the same "black depth."
 */

#include <iostream>

using namespace std;

// =============================================================================
// 10.5.1 DATA STRUCTURES AND TYPES
// =============================================================================

enum Color { RED, BLACK };

/**
 * RBEntry: Extends a standard entry to include color.
 */
template <typename E>
class RBEntry : public E {
private:
    Color col;
protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
    Color color() const { return col; }
    bool isRed() const { return col == RED; }
    bool isBlack() const { return col == BLACK; }
    void setColor(Color c) { col = c; }
public:
    RBEntry(const K& k = K(), const V& v = V()) : E(k, v), col(BLACK) { }
    // Friend class allows RBTree to manipulate private color members
    template <typename T> friend class RBTree;
};

// =============================================================================
// 10.5.2 RED-BLACK TREE IMPLEMENTATION
// =============================================================================

template <typename E>
class RBTree : public SearchTree< RBEntry<E> > {
public:
    typedef RBEntry<E> Entry;
    typedef typename SearchTree<Entry>::Iterator Iterator;
protected:
    typedef typename Entry::Key K;
    typedef typename Entry::Value V;
    typedef SearchTree<Entry> ST;
    typedef typename ST::TPos TPos;

public:
    RBTree() : ST() {}

    /**
     * INSERTION: O(log n)
     * Initially inserts as a Red node. If the parent is also Red, it triggers 
     * a "Double Red" remedy.
     */
    Iterator insert(const K& k, const V& x) {
        TPos v = this->inserter(k, x);
        if (v == this->root())
            setBlack(v);
        else {
            setRed(v);
            remedyDoubleRed(v);
        }
        return Iterator(v);
    }

protected:
    /**
     * REMEDY DOUBLE RED:
     * Case 1: Sibling of parent is Black -> Restructure (Rotation).
     * Case 2: Sibling of parent is Red -> Recoloring (may propagate up).
     */
    
    void remedyDoubleRed(const TPos& z) {
        TPos v = z.parent();
        if (v == this->root() || v->isBlack()) return; // No violation

        if (this->sibling(v)->isBlack()) { // Case 1: Restructuring
            v = this->restructure(z);
            setBlack(v); 
            setRed(v.left()); setRed(v.right());
        }
        else { // Case 2: Recoloring
            setBlack(v); setBlack(this->sibling(v));
            TPos u = v.parent();
            if (u == this->root()) return;
            setRed(u);
            remedyDoubleRed(u); // Propagate upward
        }
    }

    /**
     * REMEDY DOUBLE BLACK (Removal):
     * Used when a black node is removed, potentially violating the depth property.
     * Case 1: Black sibling with Red child -> Restructure.
     * Case 2: Black sibling with Black children -> Recoloring (may propagate).
     * Case 3: Red sibling -> Adjustment (Rotation to make sibling black).
     */
    
    void remedyDoubleBlack(const TPos& r) {
        TPos x = r.parent();
        TPos y = this->sibling(r);
        if (y->isBlack()) {
            if (y.left()->isRed() || y.right()->isRed()) { // Case 1
                TPos z = (y.left()->isRed() ? y.left() : y.right());
                Color topColor = x->color();
                z = this->restructure(z);
                setColor(z, topColor);
                setBlack(r);
                setBlack(z.left()); setBlack(z.right());
            }
            else { // Case 2
                setBlack(r); setRed(y);
                if (x->isBlack() && !(x == this->root()))
                    remedyDoubleBlack(x);
                setBlack(x);
            }
        }
        else { // Case 3: Adjustment
            TPos z = (y == x.right() ? y.right() : y.left());
            this->restructure(z);
            setBlack(y); setRed(x);
            remedyDoubleBlack(r); // Now Case 1 or 2 will apply
        }
    }

    // Helper utilities for setting colors
    void setBlack(TPos v) { v->setColor(BLACK); }
    void setRed(TPos v) { v->setColor(RED); }
    void setColor(TPos v, Color c) { v->setColor(c); }
};

// =============================================================================
// 10.5.3 PERFORMANCE SUMMARY
// =============================================================================
/**
 * | Operation | Time Complexity | Structural Changes |
 * |-----------|-----------------|--------------------|
 * | find      | O(log n)        | None               |
 * | insert    | O(log n)        | 1 Restructuring    |
 * | erase     | O(log n)        | 2 Restructurings   |
 * * Note: Red-Black trees are favored in system libraries (like STL map) 
 * because they limit the number of rotations needed during updates.
 */

/**
 * NEXT STEP:
 * We have covered all the major balanced search trees! 
 * Would you like to see a final comparison table of AVL vs Splay vs (2,4) vs Red-Black 
 * to help you decide which to use for specific scenarios?
 */
