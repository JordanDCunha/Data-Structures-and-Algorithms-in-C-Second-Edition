/**
 * CHAPTER: WRITING A C++ PROGRAM (DESIGN, CODING, TESTING)
 * --- THE CONCEPT ---
 * 1. Design: The blueprinting phase. Focus on Responsibilities (what), 
 * Independence (autonomy), and Behaviors (how classes interact).
 * 2. Pseudo-Code: Human-readable logic using math symbols (← for assignment) 
 * and natural language to bridge the gap between ideas and code.
 * 3. Coding Tools: 
 * - CRC Cards: Index cards tracking Class, Responsibility, and Collaborators.
 * - UML Diagrams: Visual notation for software architecture.
 * 4. Readability: Use CamelCase for variables (studentName) and PascalCase for 
 * Classes (CreditCard). Avoid "magic numbers" by using named CONSTANTS.
 * 5. Testing:
 * - Method/Statement Coverage: Ensure every line is executed.
 * - Boundary Cases: Test arrays with 0 or 1 elements, or reverse-sorted data.
 * - Bottom-up vs. Top-down: Testing small units first vs. using "stubs" 
 * to simulate lower-level functions.
 * 6. Debugging: Using breakpoints in an IDE instead of just print statements.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//------------------------------------------------------------------------------
// 1.6.1 STYLE AND READABILITY
//------------------------------------------------------------------------------

/**
 * Example of high readability:
 * - Constant for "Magic Numbers"
 * - Enumeration for types
 */
const int MAX_STUDENTS = 30;
enum GradeLevel { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };

class Classroom {
public:
    // PascalCase for Class, camelCase for method
    void addStudent(const string& studentName) {
        if (currentCount < MAX_STUDENTS) {
            // Logic here...
            currentCount++;
        }
    }
private:
    int currentCount = 0;
};

//------------------------------------------------------------------------------
// 1.6.2 PSEUDO-CODE TO C++ TRANSLATION
//------------------------------------------------------------------------------

/* PSEUDO-CODE:
  Algorithm findMax(A, n):
    currentMax ← A[0]
    for i ← 1 to n-1 do
      if A[i] > currentMax then
        currentMax ← A[i]
    return currentMax
*/

int findMax(int A[], int n) {
    if (n <= 0) return -1; // Testing boundary case: empty array
    
    int currentMax = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > currentMax) {
            currentMax = A[i];
