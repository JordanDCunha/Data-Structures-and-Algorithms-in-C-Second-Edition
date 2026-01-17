/**
 * CHAPTER 12.2: DYNAMIC PROGRAMMING
 * --- THE CONCEPT ---
 * Dynamic Programming (DP) is a powerful design pattern for optimization problems.
 * It is applicable when a problem has:
 * 1. Simple Subproblems: Can be defined by a few indices.
 * 2. Subproblem Optimization: Global optimal solution contains local optimal solutions.
 * 3. Subproblem Overlap: Multiple global paths share the same subproblems.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// =============================================================================
// 12.4.1: MATRIX CHAIN-PRODUCT
// =============================================================================
/**
 * Problem: Find the most efficient way to multiply a chain of matrices.
 * Goal: Minimize scalar multiplications.
 * Complexity: O(n^3) time, O(n^2) space.
 */



long matrixChain(const vector<int>& d) {
    int n = d.size() - 1; // Number of matrices
    // N[i][j] stores minimum multiplications for Ai...Aj
    vector<vector<long>> N(n, vector<long>(n, 0));

    // b is the chain length (distance between i and j)
    for (int b = 1; b < n; ++b) {
        for (int i = 0; i < n - b; ++i) {
            int j = i + b;
            N[i][j] = LONG_MAX;
            for (int k = i; k < j; ++k) {
                long cost = N[i][k] + N[k+1][j] + (long)d[i] * d[k+1] * d[j+1];
                if (cost < N[i][j]) N[i][j] = cost;
            }
        }
    }
    return N[0][n-1];
}

// =============================================================================
// 12.4.2: LONGEST COMMON SUBSEQUENCE (LCS)
// =============================================================================
/**
 * Problem: Find the longest string that is a subsequence of both X and Y.
 * Application: DNA sequencing, file comparison (diff).
 * Complexity: O(nm) time and space.
 */



string getLCS(const string& X, const string& Y) {
    int n = X.size();
    int m = Y.size();
    // L[i][j] is the length of LCS for prefixes X[0..i-1] and Y[0..j-1]
    vector<vector<int>> L(n + 1, vector<int>(m + 1, 0));

    // 1. Fill the DP Table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    // 2. Backtrack to reconstruct the string
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs += X[i-1];
            i--; j--;
        } else if (L[i-1][j] >= L[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

// =============================================================================
// SUMMARY TABLE
// =============================================================================
/**
 * | Problem             | Subproblem Definition       | Time Complexity |
 * |---------------------|-----------------------------|-----------------|
 * | Matrix Chain-Prod   | Sub-segment Ai...Aj         | O(n^3)          |
 * | LCS                 | Prefixes X[0..i], Y[0..j]   | O(nm)           |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a memory-optimized version of LCS (using only O(min(n,m)) space)?
 * 2. Explain the "Edit Distance" problem (Levenshtein distance) used in spell-checkers?
 * 3. Provide a test case for the Matrix Chain algorithm with the example from the text?
 */
