/**
 * CHAPTER: CONTROL FLOW
 * --- THE CONCEPT ---
 * 1. If Statements: Basic decision making using boolean conditions. Supports 'else if' and 'else'.
 * 2. Switch: Efficient multi-way branching for integral types (int, char, enum). 
 * - Uses 'break' to prevent "fall-through" logic.
 * 3. While Loops:
 * - while: Tests condition BEFORE execution (0 or more iterations).
 * - do-while: Tests condition AFTER execution (1 or more iterations).
 * 4. For Loops: Encapsulates (initialization; condition; increment). 
 * - Variables declared in the initialization are local to the loop scope.
 * 5. Jumps:
 * - break: Immediately exits the innermost loop or switch.
 * - continue: Skips the rest of the current iteration and moves to the next.
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Mock functions for demonstration
void goToClass() {}
void stayAtHome() {}

//------------------------------------------------------------------------------
// 1.3.1 BRANCHING (IF AND SWITCH)
//------------------------------------------------------------------------------

void branching_demo(int snowLevel, char command) {
    // If-Else Chain
    if (snowLevel < 2) {
        goToClass();
    } else if (snowLevel < 10) {
        cout << "Go skiing!" << endl;
    } else {
        stayAtHome();
    }

    // Switch Statement
    // 
    switch (command) {
        case 'I': 
            cout << "Insert Mode" << endl; 
            break; // Essential to stop execution here
        case 'D': 
            cout << "Delete Mode" << endl; 
            break;
        default:  
            cout << "Unknown command" << endl;
            break;
    }
}

//------------------------------------------------------------------------------
// 1.3.2 LOOPS (WHILE, DO-WHILE, FOR)
//------------------------------------------------------------------------------

void loop_demo() {
    int a[5] = {10, 20, -1, 40, 50};

    // While Loop: Sum until first negative
    int i = 0;
    int sumWhile = 0;
    while (i < 5 && a[i] >= 0) {
        sumWhile += a[i++];
    }

    // For Loop: Print positive elements only
    // 
    for (int j = 0; j < 5; j++) {
        if (a[j] <= 0) continue; // Skip non-positives
        cout << "Positive element: " << a[j] << endl;
    }
}

//------------------------------------------------------------------------------
// 1.3.3 BREAK AND CONTINUE
//------------------------------------------------------------------------------

void jumps_demo() {
    int data[] = {1, 2, 3, 999, 4, 5};

    for (int i = 0; i < 6; i++) {
        if (data[i] == 999) {
            cout << "Sentinel found, breaking loop." << endl;
            break; // Exits loop entirely
        }
        if (data[i] % 2 == 0) {
            continue; // Skips even numbers
        }
        cout << "Processing odd number: " << data[i] << endl;
    }
}

int main() {
    branching_demo(5, 'I');
    loop_demo();
    jumps_demo();

    return EXIT_SUCCESS;
}
