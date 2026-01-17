/**
 * CHAPTER 9.3: ORDERED MAPS
 * --- THE CONCEPT ---
 * An Ordered Map maintains entries sorted by their keys. 
 * This allows for "nearest neighbor" queries (e.g., finding the closest 
 * flight time) which are impossible in a standard Hash Map.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// =============================================================================
// 9.3.1 THE ORDERED MAP ADT
// =============================================================================
/*
 * In addition to standard Map operations, Ordered Maps provide:
 * - firstEntry() / lastEntry(): Smallest/Largest keys.
 * - ceilingEntry(k): Least key >= k.
 * - floorEntry(k): Greatest key <= k.
 * - lowerEntry(k): Greatest key < k.
 * - higherEntry(k): Least key > k.
 */

// =============================================================================
// 9.3.2 ORDERED SEARCH TABLES (Vector-based)
// =============================================================================
/*
 * Implementation: Store entries in a sorted std::vector.
 * Pros: 
 * - Binary search allows O(log n) find time.
 * - Predictable worst-case performance (unlike Hash Tables).
 * Cons:
 * - Insert/Erase are O(n) because elements must be shifted.
 */



// =============================================================================
// 9.3.3 BINARY SEARCH
// =============================================================================
/* * Strategy: "High-Low" game. Compare key k to the middle element.
 * If k < mid, search left half; if k > mid, search right half.
 */

template <typename K, typename V>
struct Entry {
    K key;
    V value;
};

// Binary Search Algorithm: O(log n)
template <typename K, typename V>
int binarySearch(const vector<Entry<K, V>>& L, const K& k, int low, int high) {
    if (low > high) return -1; // Not found (sentinel end)
    
    int mid = (low + high) / 2;
    if (k == L[mid].key) 
        return mid;
    else if (k < L[mid].key)
        return binarySearch(L, k, low, mid - 1);
    else
        return binarySearch(L, k, mid + 1, high);
}



// =============================================================================
// 9.3.4 COMPARISON OF MAP IMPLEMENTATIONS
// =============================================================================
/*
 * | Method       | find()     | insert() | erase()  | Ordering? |
 * |--------------|------------|----------|----------|-----------|
 * | Unsorted List| O(n)       | O(1)     | O(n)     | No        |
 * | Hash Table   | O(1) exp.  | O(1) exp.| O(1) exp.| No        |
 * | Search Table | O(log n)   | O(n)     | O(n)     | Yes       |
 */

// =============================================================================
// 9.3.5 APPLICATIONS: MAXIMA SETS
// =============================================================================
/*
 * Problem: Trade-off between Cost (Key) and Speed (Value).
 * A pair (c1, p1) dominates (c2, p2) if c1 <= c2 and p1 >= p2.
 * We only want to keep "Maximum Pairs" (those not dominated).
 */



/**
 * LOGIC FOR MAXIMA SETS (Pseudo-code)
 * add(c, p):
 * 1. e = M.floorEntry(c)
 * 2. If e != end and e.speed > p, return (new point is dominated).
 * 3. e = M.ceilingEntry(c)
 * 4. While e != end and e.speed < p:
 * M.erase(e) (existing points are now dominated by the new point).
 * 5. M.put(c, p).
 */

/**
 * NEXT STEP:
 * To make updates (insert/erase) as fast as searches, we need a different 
 * structure. Would you like to explore Section 9.4: Skip Lists?
 */
