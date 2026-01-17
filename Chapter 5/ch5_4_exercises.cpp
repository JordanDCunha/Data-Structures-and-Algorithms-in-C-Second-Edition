/**
 * CHAPTER 5 EXERCISES: SOLUTIONS & IMPLEMENTATIONS
 * This file contains logic for selected Reinforcement, Creativity, 
 * and Project exercises from the text.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

// =============================================================================
// REINFORCEMENT SOLUTIONS
// =============================================================================

/**
 * R-5.3: Current size of S
 * Initial: 0
 * Operations: 25 pushes, 10 pops (3 failed)
 * Calculation: 
 * Successful pops = 10 - 3 = 7
 * Current Size = 25 (pushes) - 7 (successful pops) = 18
 */

/**
 * R-5.5: Stack Trace
 * push(5), push(3), pop() -> 3
 * push(2), push(8), pop() -> 8, pop() -> 2
 * push(9), push(1), pop() -> 1
 * push(7), push(6), pop() -> 6, pop() -> 7
 * push(4), pop() -> 4, pop() -> 9
 * Final Stack: (5)
 * Output Sequence: 3, 8, 2, 1, 6, 7, 4, 9
 */

/**
 * R-5.6: Recursive function to empty a stack
 */
template <typename E>
void emptyStack(stack<E>& S) {
    if (S.empty()) return;
    S.pop();
    emptyStack(S);
}

/**
 * R-5.7: Fully Generic Templated ArrayStack
 */
template <typename E>
class GenericArrayStack {
private:
    E* S;
    int capacity;
    int t;
public:
    GenericArrayStack(int cap = 100) : S(new E[cap]), capacity(cap), t(-1) {}
    ~GenericArrayStack() { delete[] S; }
    int size() const { return t + 1; }
    bool empty() const { return t < 0; }
    const E& top() const { return S[t]; }
    void push(const E& e) { S[++t] = e; }
    void pop() { --t; }
};

// =============================================================================
// CREATIVITY SOLUTIONS
// =============================================================================

/**
 * C-5.2: Scan stack S for x using only one Queue Q
 * Logic:
 * 1. Move everything from S to Q (Order is reversed in relation to S).
 * 2. Move everything from Q back to S (Order is original).
 * 3. Move everything from S to Q again.
 * 4. While moving from Q back to S, check if element == x.
 */
bool findInStack(stack<int>& S, int x) {
    queue<int> Q;
    bool found = false;
    int n = S.size();

    // S -> Q
    while(!S.empty()){ Q.push(S.top()); S.pop(); }
    // Q -> S (Now S is original)
    while(!Q.empty()){ S.push(Q.front()); Q.pop(); }
    // S -> Q (Again)
    while(!S.empty()){
        if(S.top() == x) found = true;
        Q.push(S.top()); S.pop();
    }
    // Q -> S (Restore original)
    while(!Q.empty()){ S.push(Q.front()); Q.pop(); }
    
    return found;
}

/**
 * C-5.8: Postfix Evaluation
 * Logic: Use a stack. If operand, push. If operator, pop two, calculate, push result.
 */


int evaluatePostfix(const vector<string>& tokens) {
    stack<int> S;
    for (const string& s : tokens) {
        if (isdigit(s[0])) {
            S.push(stoi(s));
        } else {
            int val2 = S.top(); S.pop();
            int val1 = S.top(); S.pop();
            if (s == "+") S.push(val1 + val2);
            else if (s == "-") S.push(val1 - val2);
            else if (s == "*") S.push(val1 * val2);
            else if (s == "/") S.push(val1 / val2);
        }
    }
    return S.top();
}

// =============================================================================
// PROJECT SOLUTIONS
// =============================================================================

/**
 * P-5.2: Two-Color Double-Stack
 * Implementation: One stack grows from index 0 upwards, the other from index N-1 downwards.
 */


template <typename E>
class TwoColorStack {
private:
    E* arr;
    int capacity;
    int redTop;
    int blueTop;
public:
    TwoColorStack(int N) : arr(new E[N]), capacity(N), redTop(-1), blueTop(N) {}
    
    void pushRed(const E& e) {
        if (redTop + 1 == blueTop) throw runtime_error("Stack Full");
        arr[++redTop] = e;
    }
    
    void pushBlue(const E& e) {
        if (blueTop - 1 == redTop) throw runtime_error("Stack Full");
        arr[--blueTop] = e;
    }
    
    void popRed() { if (redTop >= 0) redTop--; }
    void popBlue() { if (blueTop < capacity) blueTop++; }
};

/**
 * P-5.11: FIFO Stock Capital Gains
 */
struct StockPurchase {
    int shares;
    int price;
};

int calculateGain(const vector<string>& transactions) {
    queue<StockPurchase> ledger;
    int totalGain = 0;

    // Pseudo-logic for processing strings:
    // If "buy 100 at 20": ledger.push({100, 20});
    // If "sell 50 at 30":
    //   while (sold < 50) {
    //      StockPurchase& oldest = ledger.front();
    //      // calculate gain per share, pop if shares used up
    //   }
    return totalGain;
}

// =============================================================================
// MAIN ENTRY
// =============================================================================

int main() {
    // Demo Postfix: (5 + 2) * (8 - 3) -> 5 2 + 8 3 - *
    vector<string> postfix = {"5", "2", "+", "8", "3", "-", "*"};
    cout << "Postfix (5+2)*(8-3) = " << evaluatePostfix(postfix) << endl;

    // Demo Stack Emptying
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    emptyStack(s);
    cout << "Stack is empty: " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
