/**
 * CHAPTER 11.3 - 11.5: THE ALGORITHMIC LENS ON SORTING
 * --- OVERVIEW ---
 * This file explores the theoretical lower bounds of sorting, 
 * linear-time non-comparison sorts (Bucket & Radix), and a 
 * comparison of the "Algorithm Engineering Toolbox."
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

// =============================================================================
// 11.3: THE LOWER BOUND
// =============================================================================
/**
 * PROPOSITION 11.4: Any comparison-based sorting algorithm requires 
 * Ω(n log n) time in the worst case.
 * * Logic: 
 * 1. A sorting algorithm can be modeled as a Decision Tree.
 * 2. There are n! possible permutations of an n-element sequence.
 * 3. Each permutation must end at a unique leaf node.
 * 4. A binary tree with L leaves has height h >= log2(L).
 * 5. h >= log2(n!) ≈ n log2(n) - n log2(e) = Ω(n log n).
 */



// =============================================================================
// 11.4.1: BUCKET-SORT (LINEAR TIME)
// =============================================================================

struct Entry {
    int key; // Assumed to be in range [0, N-1]
    string value;
};

/**
 * Bucket-Sort: O(n + N) time.
 * Best when N (range) is not significantly larger than n (size).
 */
void bucketSort(vector<Entry>& S, int N) {
    // 1. Create N empty buckets
    vector<list<Entry>> B(N);

    // 2. Distribute entries into buckets based on key
    for (const auto& e : S) {
        B[e.key].push_back(e);
    }

    // 3. Collect entries back into S (preserving order for stability)
    S.clear();
    for (int i = 0; i < N; ++i) {
        for (const auto& e : B[i]) {
            S.push_back(e);
        }
    }
}

// =============================================================================
// 11.4.2: RADIX-SORT
// =============================================================================
/**
 * Radix-Sort: Sorts d-tuples (k1, k2, ..., kd) by applying STABLE
 * bucket-sort d times, from LEAST significant to MOST significant.
 * * Proposition 11.6: Sorting n pairs in range [0, N-1] takes O(d(n + N)).
 */



// =============================================================================
// 11.5: SORTING ALGORITHM COMPARISON
// =============================================================================
/**
 * THE ALGORITHM TOOLBOX:
 * * | Algorithm      | Time (Avg) | Time (Worst) | In-Place? | Stable? | Best Use Case |
 * |----------------|------------|--------------|-----------|---------|---------------|
 * | Insertion-Sort | O(n + m)   | O(n^2)       | Yes       | Yes     | Small/Almost sorted |
 * | Selection-Sort | O(n^2)     | O(n^2)       | Yes       | No      | Avoid using |
 * | Heap-Sort      | O(n log n) | O(n log n)   | Yes       | No      | Real-time/Memory limit |
 * | Merge-Sort     | O(n log n) | O(n log n)   | No        | Yes     | External memory/Disks |
 * | Quick-Sort     | O(n log n) | O(n^2)       | Yes       | No      | General purpose/Fastest |
 * | Bucket-Sort    | O(n + N)   | O(n + N)     | No        | Yes     | Small integer keys |
 */

// =============================================================================
// STABILITY EXAMPLE (Logic from Section 11.4.1)
// =============================================================================
/**
 * Stability means if Key(A) == Key(B) and A appeared before B, 
 * A will still appear before B after sorting.
 * * Example: Sorting [(2, "Apple"), (1, "Banana"), (2, "Carrot")]
 * Stable Sort:   [(1, "Banana"), (2, "Apple"), (2, "Carrot")]
 * Unstable Sort: [(1, "Banana"), (2, "Carrot"), (2, "Apple")] // Order of 2s flipped
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a Radix-Sort function for strings or multi-digit integers?
 * 2. Explore Section 11.6: Selection (finding the k-th smallest element)?
 * 3. Provide a C++ code to measure and compare the actual run-times of these algorithms?
 */
