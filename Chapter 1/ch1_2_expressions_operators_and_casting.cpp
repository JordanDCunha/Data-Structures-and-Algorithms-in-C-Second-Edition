/**
 * CHAPTER: EXPRESSIONS, OPERATORS, AND CASTING
 * --- THE CONCEPT ---
 * 1. Arithmetic: Supports +, -, *, /, and % (modulo). 
 * - Integer division results in truncation (e.g., 5/2 = 2).
 * 2. Increment/Decrement: 
 * - Prefix (++v, --v): Changes value THEN returns it.
 * - Postfix (v++, v--): Returns value THEN changes it.
 * 3. Logical Operators: !, && (AND), || (OR).
 * - Short-circuiting: If the first part of && is false (or || is true), the second part is NOT evaluated.
 * 4. Bitwise Operators: ~, &, |, ^, <<, >>. Operates on the binary representation of integers.
 * 5. Casting: Converting one type to another.
 * - C-style: (type)exp.
 * - Functional: type(exp).
 * - static_cast<type>(exp): The preferred C++ method for explicit, safer conversions.
 * 6. Precedence: Determines evaluation order (e.g., * and / before + and -). Use () to ensure clarity.
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//------------------------------------------------------------------------------
// 1.2.1 ARITHMETIC AND INCREMENT OPERATORS
//------------------------------------------------------------------------------

void arithmetic_and_increment_demo() {
    // Integer Division vs Modulo
    int quotient = 18 / 16;   // Results in 1
    int remainder = 18 % 16;  // Results in 2

    // Post-increment vs Pre-increment
    int i = 2;
    int j = i++;  // j = 2, i = 3
    int k = --i;  // i = 2, k = 2

    int a[] = {10, 20, 30, 40};
    cout << "Array index check: " << a[k++] << endl; // Prints a[2] (30), then k becomes 3
}

//------------------------------------------------------------------------------
// 1.2.2 LOGICAL SHORT-CIRCUITING
//------------------------------------------------------------------------------

struct Passenger { bool isFreqFlyer; };

void logic_demo(Passenger* p) {
    // SHORT-CIRCUIT: If p is NULL, p->isFreqFlyer is never checked, preventing a crash.
    if ((p != NULL) && p->isFreqFlyer) {
        cout << "Frequent Flyer detected." << endl;
    }
}

//------------------------------------------------------------------------------
// 1.2.3 CASTING (TRADITIONAL AND STATIC)
//----------------------------------------------------------------
