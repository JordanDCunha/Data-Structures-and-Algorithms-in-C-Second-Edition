/**
 * CHAPTER: CLASSES AND OBJECT-ORIENTED FOUNDATIONS
 * --- THE CONCEPT ---
 * 1. Encapsulation: Grouping data (members) and functions (methods) into a single unit.
 * 2. Access Control:
 * - public: Members accessible from outside the class (the "Interface").
 * - private: Members accessible only within the class (the "Implementation").
 * 3. Lifecycle Management:
 * - Constructor: Special function (same name as class) to initialize objects.
 * - Destructor: (~ClassName) Cleans up resources (like memory) when object dies.
 * 4. Rule of Three: If you manage raw memory (using 'new'), you MUST define:
 * - Destructor (to free memory).
 * - Copy Constructor (to perform a "Deep Copy" instead of a "Shallow Copy").
 * - Assignment Operator (to handle 'a = b' safely, including self-assignment).
 * 5. Friends: Keywords that allow external functions or classes to access private data.
 * 6. STL Containers: Pre-built templates like vector<T> that handle memory for you.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------
// 1.5.1 BASIC CLASS STRUCTURE (The Counter)
//------------------------------------------------------------------------------

class Counter {
public:
    Counter() : count(0) {}      // Inline constructor with Initializer List
    int getCount() const { return count; } // Accessor (const means no modification)
    void increaseBy(int x) { count += x; } // Update function
private:
    int count;                   // Private data member
};

//------------------------------------------------------------------------------
// 1.5.2 MEMORY MANAGEMENT (The Rule of Three)
//------------------------------------------------------------------------------

class Vect {
public:
    // 1. Constructor
    Vect(int n = 10) : size(n), data(new int[n]) {}

    // 2. Destructor (Prevents Memory Leaks)
    ~Vect() { delete[] data; }

    // 3. Copy Constructor (Prevents Shallow Copy/Crash)
    Vect(const Vect& a) : size(a.size), data(new int[a.size]) {
        for (int i = 0; i < size; i++) data[i] = a.data[i];
    }

    // 4. Assignment Operator (Handles self-assignment and old memory)
    Vect& operator=(const Vect& a) {
        if (this != &a) {        // Check for 'a = a'
            delete[] data;       // Clean up old memory
            size = a.size;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = a.data[i];
        }
        return *this;            // Allows chaining: a = b = c
    }

private:
    int* data;
    int size;
};

//------------------------------------------------------------------------------
// 1.5.3 CLASS FRIENDS AND STL TOOLS
//------------------------------------------------------------------------------

class Passenger {
    // Granting friend status allows external operator to see 'name'
    friend ostream& operator<<(ostream& out, const Passenger& pass);

public:
    Passenger(string nm = "None") : name(nm) {}

private:
    string name;
};

ostream& operator<<(ostream& out, const Passenger& pass) {
    out << "Passenger Name: " << pass.name;
    return out;
}

void stl_demo() {
    // STL Vectors (The "Better" Array)
    vector<int> scores(5, 0);    // 5 elements initialized to 0
    scores.push_back(100);       // Dynamically resizes
    
    // STL Strings
    string s = "Hello World";
    size_t pos = s.find("World"); // Returns index 6
    string sub = s.substr(0, 5);  // "Hello"
}

//------------------------------------------------------------------------------
// MAIN EXECUTION
//------------------------------------------------------------------------------

int main() {
    // Class usage
    Counter ctr;
    ctr.increaseBy(5);
    cout << "Counter is: " << ctr.getCount() << endl;

    // Rule of Three demo
    Vect v1(10);
    Vect v2 = v1;                // Calls Copy Constructor (Deep Copy)
    
    // Friend Operator demo
    Passenger p("Alice");
    cout << p << endl;

    stl_demo();

    return 0;
}
