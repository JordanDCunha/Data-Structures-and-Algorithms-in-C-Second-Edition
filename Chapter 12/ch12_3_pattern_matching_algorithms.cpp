/**
 * CHAPTER 12.3: PATTERN MATCHING ALGORITHMS
 * --- OVERVIEW ---
 * Pattern matching involves finding the starting index of a pattern string P 
 * of length m within a text string T of length n. 
 * This file implements Brute Force, Boyer-Moore, and KMP algorithms.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// 12.3.1: BRUTE FORCE PATTERN MATCHING
// =============================================================================
/**
 * Strategy: Check every possible alignment of P against T.
 * Worst-case Complexity: O(nm)
 */
int bruteForceMatch(const string& T, const string& P) {
    int n = T.size();
    int m = P.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && T[i + j] == P[j]) {
            j++;
        }
        if (j == m) return i; // Found a match at index i
    }
    return -1;
}



// =============================================================================
// 12.3.2: BOYER-MOORE ALGORITHM (SIMPLIFIED)
// =============================================================================
/**
 * Strategy: "Looking-Glass" (right-to-left scan) and "Character-Jump" heuristics.
 * Complexity: O(nm + |Σ|) worst case, but O(n/m) on average for large alphabets.
 */

vector<int> buildLastFunction(const string& pattern) {
    const int N_ASCII = 128;
    vector<int> last(N_ASCII, -1);
    for (int i = 0; i < pattern.size(); i++) {
        last[(unsigned char)pattern[i]] = i;
    }
    return last;
}

int BMmatch(const string& text, const string& pattern) {
    vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1; 
    if (i > n - 1) return -1;
    int j = m - 1;
    do {
        if (pattern[j] == text[i]) {
            if (j == 0) return i; // Match!
            else { i--; j--; }    // Looking-glass: move backwards
        } else {
            // Character-jump: align text char with its last occurrence in P
            i = i + m - min(j, 1 + last[(unsigned char)text[i]]);
            j = m - 1;
        }
    } while (i <= n - 1);
    return -1;
}



// =============================================================================
// 12.3.3: KNUTH-MORRIS-PRATT (KMP) ALGORITHM
// =============================================================================
/**
 * Strategy: Precompute a "Failure Function" to avoid re-scanning text characters.
 * Complexity: O(n + m) - Optimal worst-case time.
 */

vector<int> computeFailFunction(const string& pattern) {
    int m = pattern.size();
    vector<int> fail(m);
    fail[0] = 0;
    int j = 0;
    int i = 1;
    while (i < m) {
        if (pattern[j] == pattern[i]) {
            fail[i] = j + 1;
            i++; j++;
        } else if (j > 0) {
            j = fail[j - 1];
        } else {
            fail[i] = 0;
            i++;
        }
    }
    return fail;
}

int KMPmatch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return 0;
    vector<int> fail = computeFailFunction(pattern);
    int i = 0; // text index
    int j = 0; // pattern index
    while (i < n) {
        if (pattern[j] == text[i]) {
            if (j == m - 1) return i - m + 1; // Match!
            i++; j++;
        } else if (j > 0) {
            j = fail[j - 1]; // Use failure function to skip comparisons
        } else {
            i++;
        }
    }
    return -1;
}



// =============================================================================
// PERFORMANCE COMPARISON
// =============================================================================
/**
 * | Algorithm   | Best Case | Worst Case | Space    | Note                       |
 * |-------------|-----------|------------|----------|----------------------------|
 * | Brute Force | O(n)      | O(nm)      | O(1)     | Simple, but slow.          |
 * | Boyer-Moore | O(n/m)    | O(nm)      | O(|Σ|)   | Fastest for natural text.  |
 * | KMP         | O(n)      | O(n + m)   | O(m)     | Guaranteed linear time.    |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a test harness to compare the number of comparisons made by each?
 * 2. Explain the "Full" Boyer-Moore algorithm including the Good-Suffix rule?
 * 3. Demonstrate how KMP is used in DNA sequence analysis?
 */
