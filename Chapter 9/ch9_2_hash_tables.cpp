/**
 * CHAPTER 9.2: HASH TABLES
 * --- THE CONCEPT ---
 * A Hash Table is a data structure that maps keys to indices in an array
 * (called a Bucket Array). This allows for O(1) average time access.
 * Components:
 * 1. Hash Function: Maps keys to integers (hash codes) and then to indices.
 * 2. Collision Resolution: Handles cases where two keys map to the same index.
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <limits>

using namespace std;

// =============================================================================
// 9.2.1 HASH CODES (Converting Keys to Integers)
// =============================================================================
/*
 * Common Techniques:
 * - Integer Cast: For types <= sizeof(int).
 * - Polynomial Accumulation: Good for strings (accounts for character order).
 * - Cyclic Shift: Fast alternative using bitwise operators.
 */



// Example of Cyclic Shift Hash Code for strings
int stringHashCode(const char* p, int len) {
    unsigned int h = 0;
    for (int i = 0; i < len; i++) {
        h = (h << 5) | (h >> 27); // 5-bit cyclic shift
        h += (unsigned int)p[i];
    }
    return (int)h;
}

// =============================================================================
// 9.2.2 COMPRESSION FUNCTIONS (Mapping Integers to [0, N-1])
// =============================================================================
/*
 * Division Method: h(k) = |k| mod N (N should be prime).
 * MAD Method: h(k) = |ak + b| mod N.
 */

// =============================================================================
// 9.2.3 COLLISION-HANDLING SCHEMES
// =============================================================================
/*
 * 1. SEPARATE CHAINING: Each bucket points to a linked list of entries.
 * 2. OPEN ADDRESSING: Entries stored directly in the array.
 * - Linear Probing: Try index (i+1), (i+2)...
 * - Quadratic Probing: Try index (i + j^2).
 * - Double Hashing: Try index (i + j * h'(k)).
 */



// =============================================================================
// 9.2.4 HASH MAP IMPLEMENTATION (SEPARATE CHAINING)
// =============================================================================

template <typename K, typename V, typename H>
class HashMap {
public:
    // Basic Entry from 9.1
    struct Entry {
        const K first; // key
        V second;      // value
        Entry(const K& k = K(), const V& v = V()) : first(k), second(v) {}
    };

protected:
    typedef std::list<Entry> Bucket;
    typedef std::vector<Bucket> BktArray;

public:
    class Iterator {
        // ... Logic to traverse between buckets ...
    };

    HashMap(int capacity = 101) : n(0), B(capacity) {}

    int size() const { return n; }
    bool empty() const { return n == 0; }

    /**
     * FIND: O(1) average
     */
    typename Bucket::iterator findInBucket(const K& k, Bucket& bkt) {
        typename Bucket::iterator it = bkt.begin();
        while (it != bkt.end() && it->first != k) ++it;
        return it;
    }

    /**
     * PUT: O(1) average
     */
    void put(const K& k, const V& v) {
        int h = hash(k) % B.size();
        Bucket& bkt = B[h];
        typename Bucket::iterator it = findInBucket(k, bkt);
        if (it == bkt.end()) {
            bkt.push_back(Entry(k, v));
            n++;
        } else {
            it->second = v; // Replace
        }
    }

private:
    int n;          // count
    H hash;         // hash comparator
    BktArray B;     // array of lists
};

// =============================================================================
// LOAD FACTORS & REHASHING
// =============================================================================
/*
 * Load Factor (λ) = n / N.
 * - For Separate Chaining: Keep λ < 0.9.
 * - For Open Addressing: Keep λ < 0.5.
 * When λ exceeds threshold, "Rehash": Create a larger table and re-insert 
 * all elements using a new hash function.
 */



/**
 * NEXT STEP:
 * We've covered the efficiency of Hash Maps. Would you like to explore 
 * Section 9.3: Search Tables and Binary Search (Sorted Maps)?
 */
