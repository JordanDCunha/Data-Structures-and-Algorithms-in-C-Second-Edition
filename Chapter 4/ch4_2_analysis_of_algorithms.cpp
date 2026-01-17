/**
 * CHAPTER 4.2: ANALYSIS OF ALGORITHMS
 * --- THE CONCEPT ---
 * We analyze algorithms to determine their "goodness" (efficiency). 
 * 1. Experimental Studies: Measuring actual running time (limited by hardware/implementation).
 * 2. Primitive Operations: Counting low-level steps (independent of hardware).
 * 3. Asymptotic Analysis: Focusing on the growth rate (Big-Oh) as input size n -> infinity.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// =============================================================================
// 4.2.1 PREFIX AVERAGES (Efficiency Comparison)
// =============================================================================

/**
 * Version 1: Quadratic Time O(n^2)
 * Uses nested loops. For each index i, it re-sums everything from 0 to i.
 */
vector<double> prefixAverages1(const vector<double>& X) {
    int n = X.size();
    vector<double> A(n);
    for (int i = 0; i < n; i++) {
        double total = 0;
        for (int j = 0; j <= i; j++) { // Inner loop runs 1, 2, 3...n times
            total += X[j];
        }
        A[i] = total / (i + 1);
    }
    return A;
}

/**
 * Version 2: Linear Time O(n)
 * Uses a running sum. Each element is visited exactly once.
 */
vector<double> prefixAverages2(const vector<double>& X) {
    int n = X.size();
    vector<double> A(n);
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += X[i];        // Maintain prefix sum
        A[i] = s / (i + 1);
    }
    return A;
}

// =============================================================================
// 4.2.2 FAST EXPONENTIATION O(log n)
// =============================================================================

/**
 * Computes x^n using squaring technique.
 * Reduces complexity from O(n) to O(log n).
 */
double power(double x
