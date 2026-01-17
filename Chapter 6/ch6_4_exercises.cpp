/**
 * CHAPTER 6: EXERCISES
 * REINFORCEMENT & CREATIVITY
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// =============================================================================
// R-6.1 REVERSING AN ARRAY
// =============================================================================
void reverseArray(int A[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = temp;
    }
}

// =============================================================================
// R-6.3 CIRCULAR ROTATION BY DISTANCE D
// =============================================================================
// Complexity: O(n) time, O(1) space using the reversal algorithm
void rotateArray(int A[], int n, int d) {
    if (n == 0) return;
    d %= n; // handle d > n
    // Reverse first n-d elements, then last d, then whole array
    auto rev = [](int arr[], int start, int end) {
        while (start < end) swap(arr[start++], arr[end--]);
    };
    rev(A, 0, n - d - 1);
    rev(A, n - d, n - 1);
    rev(A, 0, n - 1);
}

// =============================================================================
// R-6.8 TEMPLATED SUM USING STL ITERATORS
// =============================================================================
template <typename T>
T sum(const vector<T>& v) {
    T total = 0;
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
        total += *it;
    }
    return total;
}

// =============================================================================
// R-6.5 STACK ADAPTER USING VECTOR
// =============================================================================
template <typename Elem>
class VectorStack {
private:
    vector<Elem> v;
public:
    int size() const { return v.size(); }
    bool empty() const { return v.empty(); }
    void push(const Elem& e) { v.push_back(e); }
    void pop() { if (!empty()) v.pop_back(); }
    const Elem& top() const { return v.back(); }
};

// =============================================================================
// C-6.2 SHRINKING VECTOR (shrinkToFit)
// =============================================================================
// Extends the logic of ArrayVector to reclaim unused memory.
typedef int Elem;
class ShrinkingVector {
private:
    Elem* A;
    int n;
    int capacity;
public:
    ShrinkingVector() : A(NULL), n(0), capacity(0) {}
    
    void shrinkToFit() {
        if (n == capacity) return;
        capacity = n;
        Elem* B = new Elem[capacity];
        for (int i = 0; i < n; i++) B[i] = A[i];
        delete[] A;
        A = B;
    }
    // ... other methods omitted for brevity
};

// =============================================================================
// C-6.13 FISHER-YATES SHUFFLE
// =============================================================================
// Guarantees every permutation is equally likely. O(n) time.
void shuffle(vector<int>& v) {
    for (int i = v.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(v[i], v[j]);
    }
}
