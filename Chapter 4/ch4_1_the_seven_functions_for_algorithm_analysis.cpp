/**
 * CHAPTER 4.1: THE SEVEN FUNCTIONS FOR ALGORITHM ANALYSIS
 * --- THE CONCEPT ---
 * To analyze the efficiency of algorithms, we focus on how their running time
 * grows as the input size (n) increases. We use seven primary functions
 * to categorize this growth.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

// =============================================================================
// 4.1.1 THE SEVEN FUNDAMENTAL FUNCTIONS
// =============================================================================

/**
 * 1. Constant Function: f(n) = c
 * Growth is independent of n. Example: access array by index.
 */
double constantFunc(int n) { return 1.0; }

/**
 * 2. Logarithm Function: f(n) = log(n)
 * Base 2 is assumed in CS. Example: Binary search.
 */
double logFunc(int n) { return (n > 0) ? log2(n) : 0; }

/**
 * 3. Linear Function: f(n) = n
 * Work is proportional to input. Example: Finding max in an array.
 */
double linearFunc(int n) { return (double)n; }

/**
 * 4. N-Log-N Function: f(n) = n log n
 * Slightly faster growth than linear. Example: Efficient sorting (MergeSort).
 */
double nLogNFunc(int n) { return (n > 0) ? n * log2(n) : 0; }

/**
 * 5. Quadratic Function: f(n) = n^2
 * Work grows as the square of input. Example: Nested loops (BubbleSort).
 */
double quadraticFunc(int n) { return pow(n, 2); }

/**
 * 6. Cubic Function: f(n) = n^3
 * Example: Certain 3D matrix operations.
 */
double cubicFunc(int n) { return pow(n, 3); }

/**
 * 7. Exponential Function: f(n) = a^n (usually 2^n)
 * Infeasible for large n. Example: Solving the Traveling Salesman Problem.
 */
double exponentialFunc(int n) { return pow(2, n); }

// =============================================================================
// 4.1.2 MATHEMATICAL PROPOSITIONS
// =============================================================================

/**
 * Proposition 4.3 (Sum of first n integers):
 * sum = 1 + 2 + ... + n = n(n+1)/2
 */

long long arithmeticSum(int n) {
    return (long long)n * (n + 1) / 2;
}

/**
 * Proposition 4.5 (Geometric Sum):
 * sum = a^0 + a^1 + ... + a^n = (a^(n+
