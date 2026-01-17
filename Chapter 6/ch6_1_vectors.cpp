/**
 * CHAPTER 6.1: VECTORS (ARRAY LISTS)
 * --- THE CONCEPT ---
 * A Vector is an ADT that stores elements in a linear order, accessible by 
 * an integer index. Unlike a simple array, a Vector ADT explicitly 
 * supports insertion and deletion at any index, shifting other elements 
 * as needed to maintain a contiguous sequence.
 */

#include <iostream>
#include <algorithm> // for std::max
#include <vector>    // STL Vector
#include <stdexcept>

using namespace std;

// =============================================================================
// 6.1.1 THE VECTOR ADT
// =============================================================================
/*
 * CORE OPERATIONS:
 * at(i):      Return element at index i (0 to n-1).
 * set(i, e):  Replace element at index i with e.
 * insert(i, e): Insert e at index i, shifting elements at i...n-1 up.
 * erase(i):   Remove element at index i, shifting elements at i+1...n-1 down.
 */



// =============================================================================
// 6.1.3 EXTENDABLE ARRAY IMPLEMENTATION (ArrayVector)
// =============================================================================
/*
 * Problem: Static arrays have fixed capacity N.
 * Solution: When n == capacity, "Grow" the array.
 * Strategy: 
 * 1. Allocate new array B of size 2 * capacity.
 * 2. Copy A to B.
 * 3. Delete old A.
 */



typedef int Elem;

class ArrayVector {
private:
    int capacity; // actual size of array A
    int n;        // number of elements currently in vector
    Elem* A;      // array storage
public:
    ArrayVector() : capacity(0), n(0), A(NULL) {}

    int size() const { return n; }
    bool empty() const { return n == 0; }

    // Accessors
    Elem& operator[](int i) { return A[i]; }
    
    Elem& at(int i) {
        if (i < 0 || i >= n) throw out_of_range("Index out of bounds");
        return A[i];
    }

    // GROWING THE ARRAY (Amortized O(1) for push_back)
    void reserve(int N) {
        if (capacity >= N) return;
        Elem* B = new Elem[N];
        for (int j = 0; j < n; j++) B[j] = A[j];
        if (A != NULL) delete[] A;
        A = B;
        capacity = N;
    }

    // INSERTION: O(n) due to shifting
    void insert(int i, const Elem& e) {
        if (n >= capacity) 
            reserve(max(1, 2 * capacity)); // Double the capacity
        for (int j = n - 1; j >= i; j--)   // Shift elements UP
            A[j + 1] = A[j];
        A[i] = e;
        n++;
    }

    // DELETION: O(n) due to shifting
    void erase(int i) {
        for (int j = i + 1; j < n; j++)    // Shift elements DOWN
            A[j - 1] = A[j];
        n--;
    }
};

// =============================================================================
// AMORTIZED ANALYSIS: THE CYBER-DOLLAR INTUITION
// =============================================================================
/*
 * Why double the size? (Why not just add 10?)
 * If we double, the cost of copying n elements is spread out (amortized)
 * over the next n/2 insertions. 
 * Charging 3 "cyber-dollars" per insertion:
 * 1 dollar: pays for the immediate insertion.
 * 2 dollars: stored as credit to pay for the future O(n) copy when the array fills.
 */



// =============================================================================
// 6.1.4 THE STL VECTOR
// =============================================================================
/*
 * The C++ Standard Template Library provides `std::vector`.
 * Key features:
 * - push_back(e): Appends to end (Amortized O(1)).
 * - pop_back():   Removes from end (O(1)).
 * - operator[]:   Fast access, no range checking.
 * - at(i):        Access with range checking.
 */

void demoSTL() {
    vector<int> V;
    V.push_back(10); // Vector is now {10}
    V.push_back(20); // Vector is now {10, 20}
    
    cout << "Size: " << V.size() << " Front: " << V.front() << endl;
    
    V.insert(V.begin() + 1, 15); // {10, 15, 20}
    V.erase(V.begin());          // {15, 20}
}

// =============================================================================
// MAIN ENTRY
// =============================================================================

int main() {
    ArrayVector v;
    v.insert(0, 7); // (7)
    v.insert(0, 4); // (4, 7)
    v.insert(2, 2); // (4, 7, 2)
    
    cout << "Element at index 1: " << v.at(1) << endl; // 7
    
    v.erase(1);     // (4, 2)
    cout << "New element at index 1: " << v.at(1) << endl; // 2

    demoSTL();
    return 0;
}
