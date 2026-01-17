/**
 * CHAPTER 14.2: EXTERNAL MEMORY AND CACHING
 * --- THE MEMORY HIERARCHY ---
 * Modern computers use a hierarchy to balance speed, cost, and capacity.
 * 1. Registers: Fastest, smallest, inside CPU.
 * 2. Cache: Fast, stores frequently used data (SRAM).
 * 3. Main Memory (RAM): Moderate speed, holds active programs/data (DRAM).
 * 4. External Memory: Slowest, largest (Disks, SSDs, Optical drives).
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;



[Image of the memory hierarchy]


// =============================================================================
// 14.4.1: LOCALITY OF REFERENCE
// =============================================================================
/**
 * Caching works because of two principles:
 * - Temporal Locality: If data is accessed, it will likely be accessed again soon.
 * - Spatial Locality: If data is accessed, nearby data will likely be accessed soon.
 * * DESIGN CHOICES:
 * - Caching: Bringing data into faster memory (addresses temporal locality).
 * - Blocking: Bringing a whole "page" or "block" of data (addresses spatial locality).
 */



// =============================================================================
// 14.4.2: PAGE REPLACEMENT ALGORITHMS
// =============================================================================
/**
 * When the cache is full, we must decide which block to "evict."
 * - FIFO (First-In, First-Out): Oldest page is evicted.
 * - Random: A random page is evicted.
 * - LRU (Least Recently Used): The page not accessed for the longest time is evicted.
 */



// =============================================================================
// 14.4.3: LRU CACHE IMPLEMENTATION (O(1))
// =============================================================================
/**
 * To achieve O(1) for both 'get' and 'put', we use:
 * 1. A Doubly Linked List to maintain the order of usage (Most Recent at Front).
 * 2. A Hash Map (unordered_map) to provide instant access to list nodes.
 */
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; // Stores {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        
        // Move the accessed item to the front (Most Recently Used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update existing key and move to front
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        } else {
            // Check capacity
            if (cacheList.size() == capacity) {
                // Evict the Least Recently Used (back of the list)
                int lastKey = cacheList.back().first;
                cacheMap.erase(lastKey);
                cacheList.pop_back();
            }
            // Insert new item at the front
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};

/**
 * ANALYSIS SUMMARY:
 * | Strategy | Complexity | Effectiveness |
 * |----------|------------|---------------|
 * | Random   | O(1)       | Low           |
 * | FIFO     | O(1)       | Moderate      |
 * | LRU      | O(1)* | High          |
 * *LRU requires more complex pointers/hashing to maintain O(1).
 * * WOULD YOU LIKE ME TO:
 * 1. Simulate a comparison between FIFO and LRU using a specific request sequence?
 * 2. Explain Belady's Anomaly (where increasing cache size can increase misses in FIFO)?
 * 3. Discuss B-Trees, which are data structures specifically optimized for blocking and disk access?
 */
