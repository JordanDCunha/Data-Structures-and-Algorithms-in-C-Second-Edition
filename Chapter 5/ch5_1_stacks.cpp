/**
 * CHAPTER 5: STACKS
 * --- THE CONCEPT ---
 * A Stack is a LIFO (Last-In, First-Out) data structure.
 * Imagine a PEZ dispenser or a stack of plates: the last item 
 * pushed on is the first one popped off.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack> // Standard Template Library Stack

using namespace std;

// =============================================================================
// 5.1 THE STACK ADT (Abstract Data Type)
// =============================================================================
/*
 * CORE OPERATIONS:
 * push(e):  Add element e to the top.
 * pop():    Remove the top element.
 * top():    Return a reference to the top element.
 * size():   Return number of elements.
 * empty():  Return true if no elements exist.
 */



// =============================================================================
// 5.2 ARRAY-BASED STACK IMPLEMENTATION
// =============================================================================
/*
 * We use an array S and an integer 't' representing the index of the top.
 * t = -1 means the stack is empty.
 * Performance: All operations are O(1).
 */



template <typename E>
class ArrayStack {
private:
    E* S;               // Array of elements
    int capacity;       // Maximum size
    int t;              // Index of top element
public:
    ArrayStack(int cap = 100) : S(new E[cap]), capacity(cap), t(-1) {}
    
    int size() const { return t + 1; }
    bool empty() const { return t < 0; }
    
    const E& top() const {
        if (empty()) throw std::runtime_error("Stack Empty");
        return S[t];
    }
    
    void push(const E& e) {
        if (size() == capacity) throw std::runtime_error("Stack Full");
        S[++t] = e;
    }
    
    void pop() {
        if (empty()) throw std::runtime_error("Stack Empty");
        --t;
    }
};

// =============================================================================
// 5.3 STACK APPLICATION: REVERSING A VECTOR
// =============================================================================

template <typename E>
void reverseVector(vector<E>& V) {
    ArrayStack<E> S(V.size());
    for (int i = 0; i < V.size(); i++)
        S.push(V[i]);
    for (int i = 0; i < V.size(); i++) {
        V[i] = S.top(); 
        S.pop();
    }
}

// =============================================================================
// 5.4 STACK APPLICATION: HTML TAG MATCHING
// =============================================================================

/**
 * Validates if HTML tags like <body> and </body> are correctly nested.
 * 1. Opening tag (<center>): Push onto stack.
 * 2. Closing tag (</center>): Pop from stack and ensure names match.
 */
bool isHtmlMatched(const vector<string>& tags) {
    stack<string> S; // Using STL stack for convenience
    for (const string& tag : tags) {
        if (tag[1] != '/') { // Opening tag?
            S.push(tag);
        } else {             // Closing tag
            if (S.empty()) return false;
            
            // Strip brackets to compare names: <name> vs </name>
            string open = S.top().substr(1, S.top().length() - 2);
            string close = tag.substr(2, tag.length() - 3);
            
            if (open != close) return false;
            S.pop();
        }
    }
    return S.empty(); // Should be empty if all matched
}

// =============================================================================
// MAIN DEMONSTRATION
// =============================================================================

int main() {
    // 1. ArrayStack Demo
    ArrayStack<string> pez(10);
    pez.push("Cherry");
    pez.push("Orange");
    cout << "Top candy: " << pez.top() << endl; // Orange
    
    // 2. Vector Reversal Demo
    vector<int> nums = {1, 2, 3, 4, 5};
    reverseVector(nums);
    cout << "Reversed: " << nums[0] << " " << nums[4] << endl; // 5 1
    
    // 3. HTML Matching Demo
    vector<string> html = {"<body>", "<h1>", "</h1>", "</body>"};
    if (isHtmlMatched(html)) {
        cout << "HTML is valid." << endl;
    }

    return 0;
}
