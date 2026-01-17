/**
 * CHAPTER 9.5: DICTIONARIES (MULTIMAPS)
 * --- THE CONCEPT ---
 * A Dictionary is similar to a Map, but it allows for DUPLICATE keys.
 * Examples: 
 * - An English dictionary (one word, multiple definitions).
 * - A flight database (multiple flights from the same city).
 * - A game (multiple players in the same room).
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// =============================================================================
// 9.5.1 THE DICTIONARY ADT
// =============================================================================
/*
 * Key Differences from Map:
 * - find(k): Returns ANY entry with key k.
 * - findAll(k): Returns a Range (pair of iterators) for all entries with key k.
 * - insert(k, v): Always inserts, even if key k already exists.
 * - erase(k): Removes an arbitrary entry with key k.
 */

// =============================================================================
// 9.5.2 C++ IMPLEMENTATION: HashDict
// =============================================================================
/**
 * HashDict inherits from HashMap. 
 * To support findAll, it ensures that entries with the same key 
 * are stored contiguously in the same bucket.
 */

template <typename K, typename V, typename H>
class HashDict : public HashMap<K, V, H> {
public:
    typedef typename HashMap<K, V, H>::Iterator Iterator;
    typedef typename HashMap<K, V, H>::Entry Entry;

    // A Range represents a subset of the dictionary [begin, end)
    class Range {
    private:
        Iterator _begin;
        Iterator _end;
    public:
        Range(const Iterator& b, const Iterator& e) : _begin(b), _end(e) {}
        Iterator& begin() { return _begin; }
        Iterator& end() { return _end; }
    };

    HashDict(int capacity = 100) : HashMap<K, V, H>(capacity) {}

    /**
     * INSERT: O(1) average
     * Finds the first occurrence of k and inserts the new one right before it.
     */
    Iterator insert(const K& k, const V& v) {
        Iterator p = this->finder(k);           // Utility from HashMap
        Iterator q = this->inserter(p, Entry(k, v)); 
        return q;
    }

    /**
     * FINDALL: O(s) where s is the number of duplicates
     * Returns a Range for all entries matching key k.
     */
    Range findAll(const K& k) {
        Iterator b = this->finder(k); 
        Iterator p = b;
        // Since we insert duplicates contiguously, we just scan forward
        while (!this->endOfBkt(p) && (*p).key() == (*b).key()) {
            ++p;
        }
        return Range(b, p);
    }
};

// =============================================================================
// 9.5.3 LOCATION-AWARE ENTRIES
// =============================================================================
/*
 * By storing a "pointer" (or iterator) inside the Entry object that points 
 * back to its own position in the data structure, we can perform 
 * deletions in O(1) if we already have the Entry object.
 */



[Image of a human digestive system]
 
// Note: While the text mentions "castle maps" and "games", there are no 
// relevant technical diagrams for Dictionary ADT internal memory layouts 
// provided in the source text for this specific section.

/**
 * PERFORMANCE SUMMARY (With Location-Aware Entries):
 * | Implementation | erase(p) Time |
 * |----------------|---------------|
 * | Unordered List | O(1)          |
 * | Hash Table     | O(1) expected |
 * | Search Table   | O(n)          |
 * | Skip List      | O(log n) exp. |
 */

/**
 * NEXT STEP:
 * We have completed the Map and Dictionary implementations. 
 * Would you like me to summarize the performance trade-offs between 
 * all Chapter 9 data structures to help you choose the right one for a project?
 */
