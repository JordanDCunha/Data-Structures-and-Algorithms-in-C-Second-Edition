/**
 * CHAPTER 3.5: RECURSION
 * --- THE CONCEPT ---
 * 1. Self-Reference: A function that calls itself to solve a smaller version of the same problem.
 * 2. Base Case: The condition that stops the recursion (prevents infinite loops).
 * 3. Recursive Step: The part where the function calls itself with a reduced input.
 * 4. Recursion Trace: A visual way to track the sequence of calls and returns.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// =============================================================================
// 3.5.1 THE FACTORIAL FUNCTION (Linear Recursion)
// =============================================================================

/**
 * Computes n! = n * (n-1) * ... * 1
 */

int recursiveFactorial(int n) {
    if (n == 0) return 1;                   // Base case
    else return n * recursiveFactorial(n - 1); // Recursive case
}

// =============================================================================
// 3.5.2 DRAWING AN ENGLISH RULER (Binary/Multiple Recursion)
// =============================================================================

/**
 * Draws a single tick of a given length with an optional label.
 */
void drawOneTick(int tickLength, int tickLabel = -1) {
    for (int i = 0; i < tickLength; i++)
        cout << "-";
    if (tickLabel >= 0) cout << " " << tickLabel;
    cout << "\n";
}

/**
 * drawTicks(L) draws the interval between major markings.
 * Structure: Draw pattern of (L-1), Draw Tick L, Draw pattern of (L-1).
 */

void drawTicks(int tickLength) {
    if (tickLength > 0) {                   // Base case: do nothing if length is 0
        drawTicks(tickLength - 1);          // Recursively draw "left" pattern
        drawOneTick(tickLength);            // Draw center tick
        drawTicks(tickLength - 1);          // Recursively draw "right" pattern
    }
}

void drawRuler(int nInches, int majorLength) {
    drawOneTick(majorLength, 0);            // Draw 0 inch mark
    for (int i = 1; i <= nInches; i++) {
        drawTicks(majorLength - 1);         // Draw sub-markings
        drawOneTick(majorLength, i);        // Draw next inch mark
    }
}

// =============================================================================
// 3.5.3 LINEAR RECURSION EXAMPLES
// =============================================================================

/**
 * Summing elements of an array.
 * Note: This is NOT tail-recursive because the addition happens AFTER the call.
 */

int linearSum(int A[], int n) {
    if (n == 1) return A[0];
    else return linearSum(A, n - 1) + A[n - 1];
}

/**
 * Reversing an array using tail recursion.
 * The recursive call is the absolute last operation.
 */
void reverseArray(int A[], int i, int j) {
    if (i < j) {
        swap(A[i], A[j]);
        reverseArray(A, i + 1, j - 1);      // Tail Recursive call
    }
}

// =============================================================================
// 3.5.4 BINARY AND MULTIPLE RECURSION
// =============================================================================

/**
 * Fibonacci via Binary Recursion (Inefficient: Exponential Time O(2^n))
 */
int binaryFib(int k) {
    if (k <= 1) return k;
    else return binaryFib(k - 1) + binaryFib(k - 2);
}

/**
 * Fibonacci via Linear Recursion (Efficient: Linear Time O(n))
 * Returns a pair: {F_k, F_k-1}
 */
struct FibPair { int current; int previous; };

FibPair linearFibonacci(int k) {
    if (k <= 1) return {k, 0};
    else {
        FibPair p = linearFibonacci(k - 1);
        return {p.current + p.previous, p.current};
    }
}

/**
 * Binary Sum: Sums an array by splitting it in half.
 * Space complexity is O(log n) due to the depth of the recursion tree.
 */

int binarySum(int A[], int i, int n) {
    if (n == 1) return A[i];
    return binarySum(A, i, n / 2) + binarySum(A, i + n / 2, n - n / 2);
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    cout << "--- Factorial ---" << endl;
    cout << "5! = " << recursiveFactorial(5) << endl;

    cout << "\n--- English Ruler (1 inch, major length 4) ---" << endl;
    drawRuler(1, 4);

    cout << "\n--- Array Summing (Linear) ---" << endl;
    int arr[] = {4, 3, 6, 2, 5};
    cout << "Sum: " << linearSum(arr, 5) << endl;

    cout << "\n--- Fibonacci (Linear) ---" << endl;
    FibPair f = linearFibonacci(6);
    cout << "F(6) = " << f.current << endl;

    return 0;
}
