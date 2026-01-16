/**
 * CHAPTER: EXCEPTIONS
 * --- THE CONCEPT ---
 * 1. Exceptions: Objects representing unexpected events (errors or unanticipated inputs).
 * 2. Throwing: When code detects an error, it "throws" an exception object.
 * 3. Catching: A "try" block executes code; "catch" blocks handle specific exceptions.
 * 4. Hierarchy: Catching a base class (e.g., MathException) also catches its 
 * derived classes (e.g., ZeroDivide).
 * 5. Propagation: If an exception isn't caught in the current function, it 
 * "bubbles up" the call stack to the caller.
 */

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 2.4.1 EXCEPTION HIERARCHY
// =============================================================================

/**
 * 
 */

class RuntimeException { 
public:
    RuntimeException(const string& err) : errorMsg(err) {}
    string getMessage() const { return errorMsg; }
private:
    string errorMsg;
};

// Specialized exceptions via inheritance
class MathException : public RuntimeException {
public:
    MathException(const string& err) : RuntimeException(err) {}
};

class ZeroDivide : public MathException {
public:
    ZeroDivide(const string& err) : MathException(err) {}
};

// =============================================================================
// 2.4.2 THROWING AND CATCHING
// =============================================================================

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        // Throwing an anonymous object of type ZeroDivide
        throw ZeroDivide("Math Error: Attempted to divide by zero.");
    }
    return numerator / denominator;
}

/**
 * Exception Specification (Note: throw() is deprecated in modern C++, 
 * replaced by 'noexcept' in C++11 and later, but used here per text context).
 */
void calculator() throw(ZeroDivide) {
    double n, d;
    cout << "Enter numerator and denominator: ";
    cin >> n >> d;
    
    try {
        cout << "Result: " << divide(n, d) << endl;
    } 
    catch (ZeroDivide& e) {
        // Specific handler
        cout << "Caught specific error: " << e.getMessage() << endl;
    }
    catch (MathException& e) {
        // Generic math handler (would catch NegativeRoot, etc.)
        cout << "Caught general math error: " << e.getMessage() << endl;
    }
    catch (...) {
        // "Catch-all": handles any exception type not previously caught
        cout << "An unknown exception occurred." << endl;
    }
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    calculator();
    
    /**
     * 
     */
    
    return 0;
}
