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
// =================
