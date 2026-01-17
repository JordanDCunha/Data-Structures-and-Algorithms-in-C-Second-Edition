/**
 * CHAPTER 11.7: SELECTION
 * --- THE CONCEPT ---
 * The selection problem involves finding the kth smallest element in an 
 * unsorted collection. While sorting allows this in O(n log n), the 
 * "Prune-and-Search" (or Decrease-and-Conquer) strategy allows for 
 * an expected O(n) performance.
 * * * Time Complexity:
 * - Average/Expected: O(n)
 * - Worst Case: O(n^2)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// =============================================================================
// 11.7.1: RANDOMIZED QUICK-SELECT
// =============================================================================

/**
 * quickSelect: Finds the kth smallest element in vector S.
 * Note: k is 1-indexed (e.g., k=1 is the minimum).
 */
template <typename E>
E quickSelect(vector<E>& S, int k) {
    if (S.size() == 1) return S[0];

    // Pick a random pivot
    E x = S[rand() % S.size()];

    // Divide: Partition into L, E, and G
    vector<E> L, E_list, G;
    for (const E& element : S) {
        if (element < x) L.push_back(element);
        else if (element == x) E_list.push_back(element);
        else G.push_back(element);
    }

    // Prune and Search: Decide which partition to recurse into
    if (k <= L.size()) {
        return quickSelect(L, k);           // Target is in the smaller elements
    } 
    else if (k <= L.size() + E_list.size()) {
        return x;                           // Pivot is the kth smallest
    } 
    else {
        // Target is in the larger elements; adjust k for the new sequence
        return quickSelect(G, k - L.size() - E_list.size());
    }
}



// =============================================================================
// 11.7.2: PROBABILISTIC ANALYSIS
// =============================================================================
/**
 * PROPOSITION 11.11: Expected running time is O(n).
 * * * "Good" Partition: A pivot is good if |L| and |G| are ≤ 3n/4.
 * * Probability: A random pivot is "good" with probability 1/2.
 * * Expectation: We expect to find a good pivot in 2 tries.
 * * Recurrence: T(n) ≤ T(3n/4) + 2cn
 * Expanding the geometric series:
 * T(n) ≤ 2cn (1 + 3/4 + (3/4)^2 + ...)
 * Since the series converges to 4, T(n) is bounded by 8cn, which is O(n).
 */



// =============================================================================
// SUMMARY OF ORDER STATISTICS
// =============================================================================
/**
 * | Rank k         | Common Name       | Quick-Select Complexity |
 * |----------------|-------------------|-------------------------|
 * | k = 1          | Minimum           | O(n)                    |
 * | k = n          | Maximum           | O(n)                    |
 * | k = n/2        | Median            | O(n) (Expected)         |
 * | General k      | kth Order Stat    | O(n) (Expected)         |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement an in-place version of Quick-Select to save memory?
 * 2. Show the "Median-of-Medians" algorithm for a deterministic O(n) worst-case?
 * 3. Provide a test harness to compare the speed of Quick-Select vs. std::sort?
 */
