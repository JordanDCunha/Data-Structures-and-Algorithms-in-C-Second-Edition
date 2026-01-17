/**
 * CHAPTER 9.4: SKIP LISTS
 * --- THE CONCEPT ---
 * A Skip List is a randomized data structure that allows for O(log n) 
 * average time search, insertion, and removal. It consists of a series
 * of sorted linked lists {S0, S1, ..., Sh} where:
 * - S0 contains all entries.
 * - Each higher level Si contains a random subset of entries from Si-1.
 * - Sh contains only -inf and +inf.
 */

#include <iostream>
#include <vector>
#include <cstdlib> // For rand()

using namespace std;

// =============================================================================
// 9.4.1 STRUCTURE AND VISUALIZATION
// =============================================================================
/*
 * Skip lists use "Towers" (vertical links) and "Levels" (horizontal links).
 * We "flip a coin" to decide how high a new entry's tower should be.
 */



// =============================================================================
// 9.4.2 SKIP LIST SEARCH
// =============================================================================
/* * Strategy: Start at the top-left (-inf at highest level).
 * 1. Scan Forward: Move right while the next key <= search key k.
 * 2. Drop Down: If the next key > k, move to the level below.
 * Result: The largest entry in S0 with key <= k.
 */



/**
 * Algorithm SkipSearch(k):
 * p = startNode
 * while below(p) != null:
 * p = below(p)
 * while k >= key(after(p)):
 * p = after(p)
 * return p
 */

// =============================================================================
// 9.4.3 INSERTION (RANDOMIZED)
// =============================================================================
/* * 1. Find the position p in S0 using SkipSearch(k).
 * 2. Insert the entry at the bottom level.
 * 3. While coinFlip() == HEADS:
 * - Climb up one level and insert the entry again.
 * - Link it to the node below to form a "Tower".
 */



// =============================================================================
// 9.4.4 REMOVAL
// =============================================================================
/* * 1. SkipSearch(k) to find the entry.
 * 2. If found, traverse the entire tower (using above/below) 
 * and remove the entry from every level it occupies.
 */



// =============================================================================
// 9.4.5 PROBABILISTIC ANALYSIS
// =============================================================================
/**
 * PERFORMANCE SUMMARY:
 * - Expected Height: O(log n).
 * - Expected Search Time: O(log n) (Avg. 2 steps per level).
 * - Expected Space: O(n) (Total nodes = n + n/2 + n/4 ... = 2n).
 * * | Operation        | Time Complexity (Expected) |
 * |------------------|----------------------------|
 * | find / put / erase| O(log n)                  |
 * | first / lastEntry | O(log n)* |
 * | space usage       | O(n)                      |
 * *Note: If a pointer to the bottom-left is kept, firstEntry can be O(1).
 */

// =============================================================================
// A SIMPLE C++ SKIP LIST NODE (CONCEPTUAL)
// =============================================================================

template <typename K, typename V>
struct SkipNode {
    K key;
    V value;
    SkipNode *next, *prev, *up, *down;
    
    SkipNode(K k, V v) : key(k), value(v), 
        next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

/**
 * NEXT STEP:
 * Skip Lists are efficient, but what if you need more than one value 
 * per key? Would you like to explore Section 9.5: Multimaps?
 */
