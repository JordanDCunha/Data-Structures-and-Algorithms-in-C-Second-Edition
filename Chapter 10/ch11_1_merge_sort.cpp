/**
 * CHAPTER 11.1: MERGE-SORT
 * --- THE CONCEPT ---
 * Merge-sort is a sorting algorithm based on the Divide-and-Conquer paradigm.
 * 1. Divide: Split the sequence S into two subsequences S1 and S2.
 * 2. Recur: Recursively sort S1 and S2.
 * 3. Conquer: Merge the sorted S1 and S2 back into a single sorted sequence S.
 * * Time Complexity: O(n log n) in all cases.
 * Space Complexity: O(n) for auxiliary structures.
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// 11.1.1 LIST-BASED MERGE-SORT (RECURSIVE)
// =============================================================================

/**
 * Merge Utility for Lists: Combines two sorted lists into one.
 * Time: O(n1 + n2)
 */
template <typename E, typename C>
void merge(list<E>& S1, list<E>& S2, list<E>& S, const C& less) {
    typedef typename list<E>::iterator Itor;
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    
    while (p1 != S1.end() && p2 != S2.end()) {
        if (less(*p1, *p2))
            S.push_back(*p1++);
        else
            S.push_back(*p2++);
    }
    // Copy remaining elements
    while (p1 != S1.end()) S.push_back(*p1++);
    while (p2 != S2.end()) S.push_back(*p2++);
}

/**
 * Recursive Merge-Sort for STL Lists.
 */
template <typename E, typename C>
void mergeSort(list<E>& S, const C& less) {
    int n = S.size();
    if (n <= 1) return; // Base case: 0 or 1 elements are already sorted

    list<E> S1, S2;
    typename list<E>::iterator p = S.begin();
    
    // Divide: Split S into halves S1 and S2
    for (int i = 0; i < n/2; i++) S1.push_back(*p++);
    for (int i = n/2; i < n; i++) S2.push_back(*p++);
    S.clear();

    // Recur: Sort the halves
    mergeSort(S1, less);
    mergeSort(S2, less);

    // Conquer: Merge results back into S
    merge(S1, S2, S, less);
}



// =============================================================================
// 11.1.2 VECTOR-BASED MERGE-SORT (ITERATIVE / BOTTOM-UP)
// =============================================================================

/**
 * Merge Utility for Vectors: Merges two adjacent sub-runs.
 */
template <typename E, typename C>
void merge(vector<E>& in, vector<E>& out, const C& less, int b, int m) {
    int i = b;                  // Run #1 start
    int j = b + m;              // Run #2 start
    int n = in.size();
    int e1 = min(b + m, n);     // Run #1 end
    int e2 = min(b + 2 * m, n); // Run #2 end
    int k = b;

    while (i < e1 && j < e2) {
        if (!less(in[j], in[i])) out[k++] = in[i++];
        else                     out[k++] = in[j++];
    }
    while (i < e1) out[k++] = in[i++];
    while (j < e2) out[k++] = in[j++];
}

/**
 * Iterative Merge-Sort for STL Vectors.
 * Avoids recursion overhead by merging level-by-level (runs of 1, 2, 4, ...).
 */
template <typename E, typename C>
void mergeSort(vector<E>& S, const C& less) {
    int n = S.size();
    vector<E> v1(S); vector<E>* in = &v1;
    vector<E> v2(n); vector<E>* out = &v2;

    // m is the length of the runs being merged (1, 2, 4, 8...)
    for (int m = 1; m < n; m *= 2) {
        for (int b = 0; b < n; b += 2 * m) {
            merge(*in, *out, less, b, m);
        }
        swap(in, out); // Swap input/output for next level
    }
    S = *in; // Final sorted result
}

// =============================================================================
// 11.1.3 MATHEMATICAL ANALYSIS: RECURRENCE EQUATIONS
// =============================================================================
/**
 * The time complexity t(n) can be defined as:
 * t(n) = b                 if n <= 1
 * t(n) = 2t(n/2) + cn      if n > 1
 * * Expanding the recurrence:
 * t(n) = 2(2t(n/4) + c(n/2)) + cn = 4t(n/4) + 2cn
 * After i steps: t(n) = (2^i)t(n/2^i) + i*cn
 * * Let 2^i = n (so i = log n):
 * t(n) = n*t(1) + (log n)*cn
 * t(n) = nb + cn log n
 * Result: O(n log n)
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a specific Comparator class to sort custom objects using this code?
 * 2. Explore Section 11.2: Quick-Sort to compare it with Merge-Sort?
 * 3. Discuss the stability of Merge-Sort and why it's preferred for linked lists?
 */
