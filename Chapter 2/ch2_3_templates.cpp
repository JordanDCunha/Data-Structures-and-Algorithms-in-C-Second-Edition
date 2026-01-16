/**
 * CHAPTER: TEMPLATES
 * --- THE CONCEPT ---
 * 1. Function Templates: Create a "blueprint" for a function that can 
 * work with any data type T (int, double, string, etc.).
 * 2. Class Templates: Allow a data structure (like a Vector or List) 
 * to store any type of data without rewriting the class logic.
 * 3. Instantiation: The process where the compiler generates a concrete 
 * version of the template (e.g., BasicVector<int>) based on your usage.
 * 4. Requirements: The type T must support the operators used in the 
 * template (e.g., if you use 'a < b', type T must have '<' defined).
 */

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 2.3.1 FUNCTION TEMPLATES
// =============================================================================

/**
 * Returns the minimum of two values of any type T.
 * 'typename' and 'class' are interchangeable here.
 */
template <typename T>
T genericMin(T a, T b) {
    return (a < b ? a : b);
}

// =============================================================================
// 2.3.2 CLASS TEMPLATES
// =============================================================================

template <typename T>
class BasicVector {
public:
    BasicVector(int capac = 10);      // Constructor
    ~BasicVector();                   // Destructor (added for robustness)
    
    // Inline implementation of indexing
    T& operator[](int i) { 
        return a[i]; 
    }

    int getCapacity() const { return capacity; }

private:
    T* a;                             // Generic array
    int capacity;
};

// Definition outside the class body
template <typename T>
BasicVector<T>::BasicVector(int capac) {
    capacity = capac;
    a = new T[capacity];              // Dynamically allocate type T
}

template <typename T>
BasicVector<T>::~BasicVector() {
    delete[] a;                       // Clean up memory
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    // 1. Using Function Templates
    cout << "Min of 3 and 4: " << genericMin(3, 4) << endl;
    cout << "Min of 'apple' and 'banana': " << genericMin(string("apple"), string("banana")) << endl;

    // 2. Using Class Templates
    BasicVector<int> iv(5);           // Integer version
    BasicVector<double> dv(20);       // Double version
    iv[0] = 42;
    
    // 3. Templated Arguments (Vector of Vectors)
    // Note the space in "> >" for older compilers to avoid bitwise shift error
    BasicVector<BasicVector<int> > matrix(5); 
    
    matrix[2][8] = 100;
    cout << "Matrix[2][8]: " << matrix[2][8] << endl;

    return 0;
}
