/**
 * CHAPTER: FUNCTIONS AND ARGUMENT PASSING
 * --- THE CONCEPT ---
 * 1. Function Components: Return type, name, argument list, and body.
 * 2. Declaration vs. Definition: 
 * - Declaration (Prototype): Informs the compiler of the function's existence (Signature).
 * - Definition: The actual implementation of the function code.
 * 3. Argument Passing:
 * - Pass-by-Value: A copy is made; the original variable is NOT modified.
 * - Pass-by-Reference (&): An alias is used; the original variable IS modified.
 * - Constant Reference (const &): Efficiently passes large objects without copying, 
 * but prevents the function from modifying them.
 * 4. Arrays: Always passed as pointers to the first element; changes affect the original array.
 * 5. Overloading: Multiple functions/operators with the same name but different argument lists.
 * 6. Inlining: Hint to the compiler to replace the function call with the actual code to save time.
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//------------------------------------------------------------------------------
// 1.4.1 FUNCTION BASICS AND PASS-BY-REFERENCE
//------------------------------------------------------------------------------

// Declaration (Prototype)
bool evenSum(int a[], int n);

void pass_demo(int value, int& ref) {
    value++; // Incrementing a copy (no effect outside)
    ref++;   // Incrementing the actual variable (aliasing)
}

//------------------------------------------------------------------------------
// 1.4.2 OVERLOADING AND OPERATORS
//------------------------------------------------------------------------------

struct Passenger {
    string name;
    int mealPref;
    bool isFreqFlyer;
    string freqFlyerNo;
};

// Function Overloading: Same name, different types
void print(int x) { cout << "Integer: " << x << endl; }
void print(const Passenger& p) { cout << "Passenger: " << p.name << endl; }

// Operator Overloading: Custom behavior for '=='
bool operator==(const Passenger& x, const Passenger& y) {
    return x.name == y.name && x.isFreqFlyer == y.isFreqFlyer;
}

// Operator Overloading: Custom behavior for '<<' (Output stream)

ostream& operator<<(ostream& out, const Passenger& pass) {
    out << pass.name << (pass.isFreqFlyer ? " (Frequent Flyer)" : "");
    return out;
}

//------------------------------------------------------------------------------
// 1.4.3 INLINE FUNCTIONS
//------------------------------------------------------------------------------

// Inline hint for short, simple tasks
inline int minVal(int x, int y) { return (x < y ? x : y); }

//------------------------------------------------------------------------------
// MAIN EXECUTION
//------------------------------------------------------------------------------

int main() {
    // Pass by Value vs Reference
    int cat = 1, dog = 5;
    pass_demo(cat, dog); 
    // cat is still 1, dog is now 6

    // Using Overloaded Print
    Passenger p1 = {"John Smith", 1, true, "12345"};
    print(10);
    print(p1);

    // Using Overloaded Operators
    cout << "Direct Output: " << p1 << endl;

    // Array argument demo
    int list[] = {4, 2, 7, 8, 5, 1};
    if (evenSum(list, 6)) {
        cout << "The sum is even" << endl;
    }

    return EXIT_SUCCESS;
}

// Definition of evenSum
bool evenSum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return (sum % 2) == 0; 
}
