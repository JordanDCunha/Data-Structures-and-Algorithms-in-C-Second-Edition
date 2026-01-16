/**
 * CHAPTER 2: INHERITANCE AND POLYMORPHISM
 * --- THE CONCEPT ---
 * 1. Inheritance: Allows a "Derived Class" to inherit data and behavior from a "Base Class."
 * - Modeled as an "is-a" relationship (e.g., Student is-a Person).
 * 2. Access Specifiers:
 * - private: Only the class itself can access.
 * - protected: The class and its children (derived classes) can access.
 * - public: Everyone can access.
 * 3. Static vs. Dynamic Binding:
 * - Static (Default): Compiler looks at the pointer type.
 * - Dynamic (Virtual): Compiler looks at the actual object type at runtime.
 * 4. Polymorphism: A base class pointer (Person*) can point to any derived 
 * object (Student*), and virtual functions will call the correct version.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =============================================================================
// FILE: Progression.h (Base Class)
// =============================================================================

/**
 * 
 */

class Progression {
public:
    Progression(long f = 0) : first(f), cur(f) { }
    virtual ~Progression() { }               // Crucial: Virtual destructor for safety
    void printProgression(int n);            // Non-virtual: generic logic
protected:
    virtual long firstValue();               // Utility to reset
    virtual long nextValue();                // Utility to advance
protected:
    long first;                              // Initial value
    long cur;                                // Current value
};

void Progression::printProgression(int n) {
    cout << firstValue();
    for (int i = 2; i <= n; i++)
        cout << ' ' << nextValue();          // Calls the version of the actual object type
    cout << endl;
}

long Progression::firstValue() {
    cur = first;
    return cur;
}

long Progression::nextValue() {
    return ++cur;
}

// =============================================================================
// FILE: DerivedProgressions.h
// =============================================================================

// ARITHMETIC: Specialization via addition
class ArithProgression : public Progression {
public:
    ArithProgression(long i = 1) : Progression(), inc(i) { }
protected:
    virtual long nextValue() override {      // Overriding base behavior
        cur += inc;
        return cur;
    }
protected:
    long inc;
};

// GEOMETRIC: Specialization via multiplication
class GeomProgression : public Progression {
public:
    GeomProgression(long b = 2) : Progression(1), base(b) { }
protected:
    virtual long nextValue() override {
        cur *= base;
        return cur;
    }
protected:
    long base;
};

// FIBONACCI: Extension (uses an extra 'prev' variable)
class FibonacciProgression : public Progression {
public:
    FibonacciProgression(long f = 0, long s = 1) 
        : Progression(f), second(s), prev(second - first) { }
protected:
    virtual long firstValue() override {
        cur = first;
        prev = second - first;
        return cur;
    }
    virtual long nextValue() override {
        long temp = prev;
        prev = cur;
        cur += temp;
        return cur;
    }
protected:
    long second;
    long prev;
};

// =============================================================================
// FILE: TestProgression.cpp
// =============================================================================

int main() {
    /** * POLYMORPHISM IN ACTION 
     * We use a base class pointer 'prog' to point to various derived types.
     */
    Progression* prog;

    cout << "Arithmetic (increment 5):\n";
    prog = new ArithProgression(5);
    prog->printProgression(10);              // Dynamic binding calls Arith::nextValue
    delete prog;

    cout << "Geometric (base 3):\n";
    prog = new GeomProgression(3);
    prog->printProgression(10);              // Dynamic binding calls Geom::nextValue
    delete prog;

    cout << "Fibonacci (start 4, 6):\n";
    prog = new FibonacciProgression(4, 6);
    prog->printProgression(10);              // Dynamic binding calls Fib::nextValue
    delete prog;

    return 0;
}
