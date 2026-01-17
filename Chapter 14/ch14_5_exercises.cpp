/**
 * CHAPTER 14 EXERCISES: MEMORY MANAGEMENT & EXTERNAL MEMORY
 * --- SOLUTIONS ---
 */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

// =============================================================================
// R-14.1: THE 64-BIT ADDRESS SPACE LIMIT
// =============================================================================
/**
 * Logic: 
 * A 64-bit address space can address 2^64 distinct bytes.
 * 2^64 bytes ≈ 18.4 exabytes (18.4 billion gigabytes).
 * If we assume one "atom" is needed to represent one bit, the total atoms
 * required for 18.4 exabytes would exceed the estimated number of atoms in 
 * the Earth's crust (and likely any realistic engineering capability). 
 * Julia's hardware limit is effectively capped by physics and material science.
 */

// =============================================================================
// R-14.6 & R-14.7: CACHE MISS COMPARISON
// =============================================================================
/**
 * Sequence: (2, 3, 4, 1, 2, 5, 1, 3, 5, 4, 1, 2, 3), Cache Size = 4
 */

// LRU (Least Recently Used) Simulation
void solveR14_6() {
    // Result: 
    // Sequence: 2, 3, 4, 1, 2, 5, 1, 3, 5, 4, 1, 2, 3
    // Misses:   M  M  M  M  H  M  H  M  H  M  H  M  M
    // Total Cache Misses: 9
    cout << "R-14.6 LRU Cache Misses: 9" << endl;
}

// FIFO (First-In, First-Out) Simulation
void solveR14_7() {
    // Result:
    // Sequence: 2, 3, 4, 1, 2, 5, 1, 3, 5, 4, 1, 2, 3
    // Misses:   M  M  M  M  H  M  M  M  H  M  M  M  M
    // Total Cache Misses: 11
    cout << "R-14.7 FIFO Cache Misses: 11" << endl;
}



// =============================================================================
// C-14.1: EXTERNAL-MEMORY DUPLICATE REMOVAL
// =============================================================================
/**
 * Algorithm:
 * 1. Perform an External Multi-Way Merge Sort on the vector. 
 * Complexity: O((n/B) log_{M/B} (n/B)) transfers.
 * 2. Perform a single linear scan of the sorted file. 
 * Since duplicates are now adjacent, read one block at a time, compare 
 * the current element with the previous, and write only unique elements 
 * to a new output file.
 * Total Transfers: O((n/B) log_{M/B} (n/B)).
 */

// =============================================================================
// C-14.13: MAJORITY ELEMENT (EXTERNAL MEMORY)
// =============================================================================
/**
 * Problem: Find a value occurring > n/2 times.
 * Strategy: Boyer-Moore Voting Algorithm (adapted for External Memory).
 * 1. Scan the file once (linear scan). 
 * Maintain a "candidate" and a "counter" in RAM.
 * - For each element 'x' read from the disk block:
 * - If counter == 0, candidate = x, counter = 1.
 * - Else if x == candidate, counter++.
 * - Else counter--.
 * 2. Perform a second linear scan to verify the candidate (count its actual occurrences).
 * Total I/O Complexity: O(n/B) transfers.
 */

// =============================================================================
// C-14.6: EXTERNAL QUEUE ADT
// =============================================================================
/**
 * Implementation:
 * Maintain two blocks (buffers) in RAM: 
 * - An "Input Buffer" for enqueuing.
 * - An "Output Buffer" for dequeuing.
 * * Logic:
 * - Enqueue: Add to Input Buffer. If full, write to Disk and clear buffer (1 transfer).
 * - Dequeue: Remove from Output Buffer. If empty, read next block from Disk (1 transfer).
 * * Over 'n' operations, each element is written to disk once and read from disk once.
 * Total transfers: O(n/B).
 */



// =============================================================================
// R-14.3 & R-14.4: (a,b) TREE PARAMETERS
// =============================================================================
/**
 * If each internal node has [5, 8] children:
 * R-14.3: Valid (a,b) tree if a <= 5 and b >= 8, AND a <= (b+1)/2.
 * With a=5, b=8: (8+1)/2 = 4.5. Since 5 > 4.5, a=5 is too high for b=8.
 * To make it valid, we need a=4 and b=8 (since 4 <= (8+1)/2).
 * * R-14.4: For a B-tree of order d, a = ceil(d/2) and b = d.
 * If d=8, then a=4. If d=9, then a=5.
 * Therefore, the tree could be a B-tree of order 8 or 9.
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Provide the C++ simulation code for Project P-14.1 (Memory Management)?
 * 2. Draw the step-by-step B-tree for the sequence in R-14.9?
 * 3. Explain the math behind the Red-Black to (4,8) tree conversion (C-14.3)?
 */
