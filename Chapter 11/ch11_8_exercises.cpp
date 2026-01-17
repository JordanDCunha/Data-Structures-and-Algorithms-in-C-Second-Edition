/**
 * CHAPTER 11 EXERCISES & SOLUTIONS
 * --- OVERVIEW ---
 * This file contains C++ implementations and conceptual solutions for 
 * selected reinforcement (R), creativity (C), and project (P) exercises
 * from Chapter 11 (Sorting and Selection).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>

using namespace std;

// =============================================================================
// REINFORCEMENT EXERCISES
// =============================================================================

/**
 * R-11.1: Best Algorithms for Types:
 * - General objects: Quick-sort (fast average-case).
 * - Long strings: Merge-sort (minimizes movement/copying).
 * - 32-bit integers: Radix-sort (O(n) if range is managed).
 * - Bytes: Bucket-sort (N=256, strictly O(n)).
 */

/**
 * R-11.8: O(n) Union of two sorted sequences (without duplicates).
 * Based on the Generic Merge Template Method.
 */
vector<int> sortedUnion(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    auto itA = A.begin(), itB = B.begin();
    while (itA != A.end() && itB != B.end()) {
        if (*itA < *itB) {
            C.push_back(*itA++);
        } else if (*itA > *itB) {
            C.push_back(*itB++);
        } else { // Equal
            C.push_back(*itA++);
            itB++; // Skip duplicate from B
        }
    }
    while (itA != A.end()) C.push_back(*itA++);
    while (itB != B.end()) C.push_back(*itB++);
    return C;
}

// =============================================================================
// CREATIVITY EXERCISES
// =============================================================================

/**
 * C-11.12: In-place 0/1 Partition.
 * Given an array of 0s and 1s, order them in O(n) time and O(1) space.
 * This is effectively the "Divide" step of quick-sort with pivot=0.
 */
void partition01(vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while (left <= right) {
        while (left <= right && A[left] == 0) left++;
        while (left <= right && A[right] == 1) right--;
        if (left < right) swap(A[left], A[right]);
    }
}



/**
 * C-11.20: Efficiently determine if duplicates exist in S.
 * Strategy: Sort S in O(n log n), then perform a linear scan.
 */
bool hasDuplicates(vector<int>& S) {
    if (S.size() <= 1) return false;
    sort(S.begin(), S.end()); // O(n log n)
    for (size_t i = 0; i < S.size() - 1; ++i) {
        if (S[i] == S[i+1]) return true; // O(n)
    }
    return false;
}

/**
 * C-11.21: Counting Inversions in O(n log n).
 * Modified Merge-Sort: Every time an element from the right half 
 * is moved into the result before the left half is empty, 
 * inversions = size of remaining left half.
 */
long countInversions(vector<int>& S) {
    if (S.size() <= 1) return 0;
    
    vector<int> left, right;
    int mid = S.size() / 2;
    for (int i = 0; i < mid; ++i) left.push_back(S[i]);
    for (int i = mid; i < S.size(); ++i) right.push_back(S[i]);
    
    long count = countInversions(left) + countInversions(right);
    
    // Merge and count
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            S[k++] = left[i++];
        } else {
            S[k++] = right[j++];
            count += (left.size() - i); // Key insight
        }
    }
    while (i < left.size()) S[k++] = left[i++];
    while (j < right.size()) S[k++] = right[j++];
    
    return count;
}



// =============================================================================
// PROJECTS
// =============================================================================

/**
 * P-11.6: Benchmarking Quick-Sort vs Insertion-Sort.
 * Observation: Insertion-sort is often faster for n < 20 due to low overhead.
 */
void benchmark() {
    // Conceptual pseudo-code for a test harness
    // 1. Generate random vectors of sizes 5, 10, 20, 50, 100.
    // 2. Measure CPU cycles for insertionSort() vs quickSort().
    // 3. Find the "crossover point."
}

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement the O(n) Radix-sort for n^2 range (Exercise C-11.18)?
 * 2. Provide the "Median-of-Medians" logic for Deterministic Selection (Exercise C-11.32)?
 * 3. Discuss the Inverted File construction (Exercise C-11.11) for Search Engines?
 */
