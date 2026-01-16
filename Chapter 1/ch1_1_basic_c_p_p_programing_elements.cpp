/**
 * CHAPTER: BASIC C_PLUS_PLUS PROGRAMMING ELEMENTS
 * --- THE CONCEPT ---
 * 1. Evolution: C++ is a superset of C, adding Object-Oriented features like Classes.
 * 2. Compilation: Source -> Compiler (Machine Code) -> Linker (Libraries) -> Executable.
 * 3. Fundamental Types: 
 * - Integral: bool, char (8-bit), int, short, long, enum.
 * - Floating Point: float, double (default for literals).
 * 4. Pointers & References:
 * - Pointers (*): Store memory addresses; can be NULL; require dereferencing.
 * - References (&): Aliases for existing variables; must be initialized; cannot be NULL.
 * 5. Memory Management:
 * - 'new' allocates memory from the Free Store (Heap).
 * - 'delete' (or 'delete[]' for arrays) must be called to prevent Memory Leaks.
 * 6. Scope & Namespaces: Local (inside {}) vs. Global. Namespaces (std::) prevent naming conflicts.
 */

#include <iostream>
#include <string>
#include <cstdlib> // For EXIT_SUCCESS

using namespace std;

//------------------------------------------------------------------------------
// 1.1.2 DATA AGGREGATION (Structs and Enums)
//------------------------------------------------------------------------------

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

struct Passenger {
    string name;
    MealType mealPref;
    bool isFreqFlyer;
    string freqFlyerNo;
};

//------------------------------------------------------------------------------
// 1.1.3 POINTERS AND DYNAMIC MEMORY
//------------------------------------------------------------------------------

void pointer_and_heap_demo() {
    // Pointer Basics
    char ch = 'Q';
    char* p = &ch;        // p holds address of ch
    *p = 'Z';             // Modifies ch via pointer

    // Dynamic Allocation (The "new" operator)
    Passenger* dynamicPass = new Passenger;
    
    // Using the arrow operator (->) to access members via pointer
    dynamicPass->name = "Pocahontas";
    dynamicPass->mealPref = REGULAR;
    dynamicPass->isFreqFlyer = false;

    // Must manually deallocate to prevent memory leaks
    delete dynamicPass;

    // Dynamic Arrays
    char* buffer = new char[500];
    buffer[0] = 'A';
    delete[] buffer;      // Note the square brackets for arrays
}

//------------------------------------------------------------------------------
// 1.1.4 REFERENCES AND CONSTANTS
//------------------------------------------------------------------------------

void reference_demo() {
    string author = "Samuel Clemens";
    string& penName = author;     // penName is an alias for author
    
    penName = "Mark Twain";       // Changes the original 'author' variable
    
    const double PI = 3.14159;    // Value cannot be changed
}

//------------------------------------------------------------------------------
// 1.1.1 A SIMPLE C++ PROGRAM (Input/Output)
//------------------------------------------------------------------------------

void io_demo() {
    int x, y;
    cout << "Please enter two numbers: ";
    if (cin >> x >> y) {          // Input operator
        int sum = x + y;
        cout << "Their sum is " << sum << endl; // Output operator
    }
}

int main() {
    // Demonstration of chapter concepts
    io_demo();
    pointer_and_heap_demo();
    reference_demo();

    return EXIT_SUCCESS; 
}
