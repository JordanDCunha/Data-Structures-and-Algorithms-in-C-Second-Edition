/**
 * CHAPTER 12.1: STRING OPERATIONS
 * --- THE CONCEPT ---
 * Text processing is a core computational function, underlying everything 
 * from DNA analysis to Internet search engines. This section defines the 
 * mathematical properties of strings and explores the C++ STL string class.
 */

#include <iostream>
#include <string> // Required for std::string

using namespace std;

// =============================================================================
// 12.1.1: MATHEMATICAL DEFINITIONS
// =============================================================================
/**
 * ALPHABET (Σ): A finite set of characters.
 * SUBSTRING: A sequence P[i..j] from index i to j.
 * PREFIX: A substring starting at index 0 (P[0..i]).
 * SUFFIX: A substring ending at the last index (P[i..m-1]).
 */



// =============================================================================
// 12.1.2: THE STL STRING CLASS
// =============================================================================
/**
 * The C++ STL provides std::string (which is basic_string<char>).
 * It manages memory automatically and provides high-level operations.
 */

void demonstrateStringOps() {
    // Initialization
    string S = "abcdefghijklmnop";

    // Basic Access
    size_t len = S.size();      // 16
    char f = S.at(5);           // 'f' (with bounds checking)
    char f2 = S[5];             // 'f' (no bounds checking)

    // Substrings and Searching
    // substr(start_index, length)
    string sub = S.substr(4, 6); // "efghij"
    
    // find(query) returns index of first occurrence or string::npos
    size_t pos = S.find("ghi");  // 6

    // Modification
    S.erase(4, 6);               // Removes "efghij", S becomes "abcdklmnop"
    S.insert(1, "xxx");          // S becomes "axxxbcdklmnop"
    S += "xy";                   // Concatenation: "axxxbcdklmnopxy"
    S.append("z");               // "axxxbcdklmnopxyz"

    // C-Style Conversion
    const char* c_str = S.c_str(); // Returns pointer to null-terminated array
}

// =============================================================================
// 12.1.3: LEXICOGRAPHICAL COMPARISON
// =============================================================================
/**
 * Relational operators (==, <, >, <=, >=) compare strings lexicographically 
 * (dictionary order).
 */
void compareStrings() {
    string s1 = "Apple";
    string s2 = "Apply";
    
    if (s1 < s2) {
        // This is true because 'e' comes before 'y'
    }
}

/**
 * DESIGN PATTERNS IN TEXT PROCESSING:
 * 1. Brute-Force: Pattern matching (simple but potentially slow).
 * 2. Greedy Method: Text compression (e.g., Huffman coding).
 * 3. Dynamic Programming: Text similarity (e.g., Edit Distance).
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a function to list all prefixes and suffixes of a given string?
 * 2. Show how to use basic_string<int> to create a "string of integers"?
 * 3. Discuss Section 12.2: Pattern Matching Algorithms (Brute-Force vs. Boyer-Moore)?
 */
