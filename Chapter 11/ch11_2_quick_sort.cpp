/**
 * CHAPTER 11.2: QUICK-SORT
 * --- THE CONCEPT ---
 * Quick-sort is a Divide-and-Conquer algorithm where the "hard work" is done 
 * during the divide step. It partitions a sequence S into elements less than, 
 * equal to, and greater than a chosen 'pivot'.
 * * * Time Complexity: 
 * - Average/Expected: O(n log n)
 * - Worst Case: O(n^2) (e.g., when the pivot is always the min/max)
 * * Space Complexity: 
 * - In-place version: O(log n) for recursion stack.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// 11.2.1 HIGH-LEVEL QUICK-SORT (LIST/GENERAL)
// =============================================================================

/**
 * Visualizing the partitioning strategy:
 * [ L (< pivot) ]  [ E (= pivot) ]  [ G (> pivot) ]
 */


// =============================================================================
// 11.2.2 IN-PLACE QUICK-SORT (VECTOR-BASED)
// =============================================================================

/**
 * quickSortStep: The core recursive utility for in-place sorting.
 * This version uses the last element as the pivot and assumes distinct elements.
 * It uses two pointers (l and r) to swap elements into their correct sides.
 */
template <typename E, typename C>
void quickSortStep(vector<E>& S, int a, int b, const C& less) {
    if (a >= b) return;               // Base case: subrange has 0 or 1 element
    
    E pivot = S[b];                   // Pivot selection (last element)
    int l = a;                        // Left boundary scan
    int r = b - 1;                    // Right boundary scan

    while (l <= r) {
        // Scan right until an element > pivot is found
        while (l <= r && !less(pivot, S[l])) l++;
        // Scan left until an element < pivot is found
        while (r >= l && !less(S[r], pivot)) r--;
        
        if (l < r) {
            swap(S[l], S[r]);         // Swap the mismatched pair
        }
    }
    // Place the pivot in its final resting position (at index l)
    swap(S[l], S[b]);

    // Recur on the two partitioned sub-ranges
    quickSortStep(S, a, l - 1, less);
    quickSortStep(S, l + 1, b, less);
}

/**
 * quickSort: Public interface for the algorithm.
 */
template <typename E, typename C>
void quickSort(vector<E>& S, const C& less) {
    if (S.size() <= 1) return;
    quickSortStep(S, 0, S.size() - 1, less);
}

// =============================================================================
// 11.2.3 RANDOMIZED QUICK-SORT & OPTIMIZATIONS
// =============================================================================

/**
 * PROPOSITION 11.3: RANDOMIZATION
 * Picking a random pivot ensures an O(n log n) expected running time, 
 * regardless of the input distribution (even if the input is sorted).
 * * MEDIAN-OF-THREE HEURISTIC:
 * Instead of a random index, pick the median of (S[first], S[mid], S[last]).
 * This is faster than generating random numbers and avoids O(n^2) for 
 * common "mostly sorted" datasets.
 */



/**
 * ANALYSIS SUMMARY:
 * | Scenario   | Tree Height | Time Complexity |
 * |------------|-------------|-----------------|
 * | Best Case  | O(log n)    | O(n log n)      |
 * | Average    | O(log n)    | O(n log n)      |
 * | Worst Case | O(n)        | O(n^2)          |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement the "Median-of-Three" pivot selection to optimize the code above?
 * 2. Discuss Section 11.3: A Comparison of Sorting Algorithms (Merge vs Quick vs Heap)?
 * 3. Explain how to handle duplicate keys in Quick-Sort (the 3-way partition)?
 */
