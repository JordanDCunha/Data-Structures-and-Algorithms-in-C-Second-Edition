/**
 * CHAPTER 2: EXERCISES - OBJECT-ORIENTED DESIGN
 * --- THE CONCEPT ---
 * This file contains implementations for selected Reinforcement (R), 
 * Creativity (C), and Project (P) exercises for Chapter 2.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// =============================================================================
// REINFORCEMENT SOLUTIONS
// =============================================================================

/**
 * R-2.1: Disadvantages of DEEP inheritance trees:
 * 1. Complexity: Harder to track where a specific member function is defined.
 * 2. Performance: Increased overhead for virtual function lookups (v-table traversal).
 * 3. Fragility: Changes in the top-level base class ripple down through many layers.
 * * R-2.2: Disadvantages of SHALLOW inheritance trees:
 * 1. Code Duplication: Lack of intermediate grouping leads to repeated code in siblings.
 * 2. Maintainability: If 50 classes share logic, you must update 50 places instead 
 * of one intermediate base class.
 */

/**
 * R-2.6: Class Inheritance Diagram (Conceptual)
 * 
 */

/**
 * R-2.8: Fibonacci starting with 3 and 4 (Finding 7th value)
 */
// (Assuming FibonacciProgression class from section 2.2.3 is available)
void r2_8_solution() {
    // Note: FibonacciProgression(first, second)
    // 3, 4, 7, 11, 18, 29, 47...
    // FibonacciProgression prog(3, 4);
    // prog.printProgression(7);
}

/**
 * R-2.13: Exception handling for out-of-bounds
 */
void r2_13_solution() {
    vector<int> data = {1, 2, 3};
    try {
        int index = 10;
        if (index >= data.size()) throw out_of_range("Index out of bounds!");
        cout << data[index] << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

/**
 * R-2.18: Templated Pair Class
 */
template <typename K, typename V>
class Pair {
public:
    Pair(K k, V v) : first(k), second(v) {}
    void print() { cout << "<" << first << ", " << second << ">" << endl; }
private:
    K first;
    V second;
};

// =============================================================================
// CREATIVITY SOLUTIONS
// =============================================================================

/**
 * C-2.4: Line intersection with Exception
 */
class ParallelException {};

class Line {
public:
    Line(double slope, double intercept) : a(slope), b(intercept) {}
    double intersect(const Line& other) {
        if (this->a == other.a) throw ParallelException();
        return (other.b - this->b) / (this->a - other.a);
    }
private:
    double a, b; // y = ax + b
};

/**
 * C-2.5: Absolute Difference Progression
 */
#include "Progression.h" // Conceptual include
class DiffProgression : public Progression {
public:
    DiffProgression(long f = 2, long s = 200) : Progression(f), second(s), prev(f + s) {}
protected:
    virtual long firstValue() {
        cur = first;
        prev = first + second; // Set up so nextValue gives 'second'
        return cur;
    }
    virtual long nextValue() {
        long next = abs(cur - prev);
        prev = cur;
        cur = next;
        return cur;
    }
private:
    long second, prev;
};

// =============================================================================
// PROJECT SOLUTIONS
// =============================================================================

/**
 * P-2.1: Count divisions by 2 until < 2
 */
int countDivisions(double n) {
    int count = 0;
    while (n >= 2.0) {
        n /= 2.0;
        count++;
    }
    return count;
}

/**
 * P-2.6: Alphabet Frequency Bar Chart
 */
void printFrequency(string doc) {
    int freq[26] = {0};
    for (char c : doc) {
        if (isalpha(c)) {
            freq[tolower(c) - 'a']++;
        }
    }
    // Simple ASCII bar chart
    for (int i = 0; i < 26; i++) {
        cout << (char)('a' + i) << ": ";
        for (int j = 0; j < freq[i]; j++) cout << "*";
        cout << " (" << freq[i] << ")" << endl;
    }
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    // Test Pair (R-2.18)
    Pair<int, string> p1(1, "Apple");
    Pair<double, long> p2(3.14, 1000L);
    p1.print();
    p2.print();

    // Test Line Intersect (C-2.4)
    Line l1(2, 5), l2(-1, 2);
    try {
        cout << "Intersection x: " << l1.intersect(l2) << endl;
    } catch (ParallelException) {
        cout << "Lines are parallel!" << endl;
    }

    return 0;
}
