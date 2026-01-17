/**
 * CHAPTER 9: MAPS, HASH TABLES, AND SKIP LISTS
 * 9.1: MAPS
 * --- THE CONCEPT ---
 * A Map (or Associative Container) stores key-value pairs (k, v).
 * It acts like a file cabinet where the key is the unique label (address) 
 * used to retrieve the folder (value).
 */

#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

// =============================================================================
// 9.1.1 THE COMPOSITION PATTERN: ENTRIES
// =============================================================================
/* * An Entry is a single object composed of a Key and a Value. 
 */
template <typename K, typename V>
class Entry {
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) { }
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setKey(const K& k) { _key = k; }
    void setValue(const V& v) { _value = v; }
private:
    K _key;
    V _value;
};



// =============================================================================
// 9.1.2 THE MAP ADT (ABSTRACT DATA TYPE)
// =============================================================================
/*
 * Essential Operations:
 * - size(), empty()
 * - find(k): Returns iterator to entry with key k, or end().
 * - put(k, v): Inserts new entry or updates value if key k exists.
 * - erase(k) / erase(p): Removes entry by key or iterator.
 * - begin() / end(): Standard iterator access.
 */

// =============================================================================
// 9.1.3 THE STL MAP CLASS
// =============================================================================
/*
 * The C++ Standard Template Library provides `std::map`.
 * Key features:
 * - Iterators are bidirectional (++p, --p).
 * - p->first accesses the Key; p->second accesses the Value.
 * - operator[]: M[k] = v (Very convenient for put/replace).
 */

void stlMapExample() {
    map<string, int> myMap;
    
    // Insertion methods
    myMap.insert(pair<string, int>("Rob", 28));
    myMap["Joe"] = 38; // Using subscript operator
    myMap["Joe"] = 50; // Replaces 38 with 50
    
    // Search
    map<string, int>::iterator p = myMap.find("Joe");
    if (p != myMap.end()) {
        cout << "Found Joe: " << p->second << endl;
    }
}

// =============================================================================
// 9.1.4 SIMPLE LIST-BASED IMPLEMENTATION
// =============================================================================
/*
 * We can store entries in a Doubly Linked List.
 * * PERFORMANCE:
 * - find(k): O(n) - Must scan the whole list.
 * - put(k, v): O(n) - Must scan to check if key exists before appending.
 * - erase(k): O(n) - Must scan to find the node.
 * * CONCLUSION: Simple to code, but inefficient for large datasets.
 */



// =============================================================================
// SUMMARY TABLE: MAP IMPLEMENTATIONS
// =============================================================================
/*
 * | Operation | Unsorted List | STL Map (Balanced Tree) |
 * |-----------|---------------|-------------------------|
 * | find      | O(n)          | O(log n)                |
 * | put       | O(n)          | O(log n)                |
 * | erase     | O(n)          | O(log n)                |
 * | size      | O(1)          | O(1)                    |
 */
