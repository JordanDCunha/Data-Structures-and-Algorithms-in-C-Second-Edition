/**
 * CHAPTER 4.3: JUSTIFICATION TECHNIQUES
 * --- THE CONCEPT ---
 * To prove an algorithm's correctness or its complexity, we use 
 * mathematical justification. This section outlines five essential 
 * techniques used throughout the book.
 */

#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 4.3.1 BY EXAMPLE (Counterexample)
// =============================================================================
/* * Claim: Every number of form (2^i - 1) is prime for i > 1.
 * Counterexample: If i = 4, 2^4 - 1 = 15. 15 is not prime (3 * 5).
 * Result: Claim is FALSE.
 */

// =============================================================================
// 4.3.2 THE "CONTRA" ATTACK (Contrapositive & Contradiction)
// =============================================================================
/*
 * Contrapositive: To prove "If P then Q", prove "If NOT Q then NOT P".
 * Example: If ab is even, then a or b is even.
 * Proof: If a is odd AND b is odd, then ab is (2i+1)(2j+1) = 2(2ij+i+j)+1 (Odd).
 *
 * Contradiction: Assume the opposite of what you want to prove and find a flaw.
 * Example: Prove "If ab is odd, then a and b are odd."
 * Proof: Assume a is even. Then ab = (2i)b = 2(ib), which is even. 
 * This contradicts the premise that ab is odd!
 */

// =============================================================================
// 4.3.3 MATHEMATICAL INDUCTION
// =============================================================================
/*
 * Steps:
 * 1. Base Case: Prove statement Q(n) for n = 1.
 * 2. Inductive Step: Assume Q(i) is true for i < n, prove Q(n) is true.
 *
 * Example: Sum of 1 to n = n(n+1)/2.
 */


int arithmeticSumRecursive(int n) {
    if (n <= 1) return 1; // Base case
    return n + arithmeticSumRecursive(n - 1); // Step: n + Sum(n-1)
}

// =============================================================================
// 4.3.4 LOOP INVARIANTS
// =============================================================================
/*
 * Technique: Define a statement S that remains true throughout the loop.
 * 1. Initial: S is true before loop.
 * 2. Maintenance: If S is true before iteration i, it's true after.
 * 3. Termination: S at the end implies correctness.
 */

/**
 * Example 4.5: arrayFind
 * Invariant Si: x is not equal to any of the first i elements of A.
 */
int arrayFind(int x, const vector<int>& A) {
    int n = A.size();
    int i = 0;
    // Before loop: S0 is true (x is not in the first 0 elements).
    while (i < n) {
        // If x == A[i], we found it.
        if (x == A[i]) return i;
        else i++; 
        // Maintenance: Since x != A[i], Si+1 is true.
    }
    // Termination: i == n, so Sn is true (x is not in all n elements).
    return -1;
}

// =============================================================================
// SUMMARY OF TECHNIQUES
// =============================================================================

/*
 * | Technique      | Best Used For...                                         |
 * |----------------|----------------------------------------------------------|
 * | Counterexample | Disproving a universal claim.                             |
 * | Contrapositive | Proving "If-Then" logic by reversing it.                 |
 * | Contradiction  | Proving something MUST be true because the opposite is impossible. |
 * | Induction      | Claims involving integers n (size, depth, time).         |
 * | Loop Invariant | Proving iterative algorithms are correct.                |
 */

int main() {
    vector<int> data = {10, 25, 30, 45, 50};
    int target = 45;

    int index = arrayFind(target, data);
    
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
