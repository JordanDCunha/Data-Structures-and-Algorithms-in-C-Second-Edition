/**
 * CHAPTER 14: MEMORY MANAGEMENT
 * --- CONCEPTS ---
 * Memory is a sequence of words, each with a unique address.
 * Management involves two primary areas: the Stack and the Heap.
 */

#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 14.1: THE C++ RUN-TIME STACK
// =============================================================================
/**
 * The Call Stack manages function invocations using "Frames."
 * Each Frame stores:
 * 1. Local variables and parameters.
 * 2. The Program Counter (where to return after the function finishes).
 * * Parameter Passing:
 * - Call-by-Value: A copy is made in the new frame.
 * - Call-by-Reference: The address is passed; both functions access the same object.
 */



// Example: Recursion using the Stack
int recursiveFactorial(int n) {
    // Each call pushes a new frame onto the stack
    if (n == 0) return 1; 
    else return n * recursiveFactorial(n - 1); 
}

// =============================================================================
// 14.2: THE MEMORY HEAP
// =============================================================================
/**
 * The Heap is used for dynamic allocation (using 'new').
 * Unlike the stack, memory here must be manually managed (in C++).
 * * Fragmentation:
 * - Internal: Unused space inside an allocated block.
 * - External: Unused space between allocated blocks.
 */



/**
 * Allocation Heuristics:
 * 1. First-fit: First hole big enough.
 * 2. Best-fit: Hole closest in size (can cause tiny, unusable fragments).
 * 3. Next-fit: Like first-fit, but starts where it last left off.
 * 4. Worst-fit: Largest available hole (tries to keep remaining holes large).
 */

// =============================================================================
// 14.3: GARBAGE COLLECTION (GC)
// =============================================================================
/**
 * GC automatically reclaims memory of "non-live" objects.
 * * Mark-Sweep Algorithm:
 * 1. Mark Phase: Start from "Root Objects" (on the stack) and perform a 
 * Directed DFS to find all reachable ("live") objects.
 * 2. Sweep Phase: Scan the heap; reclaim any object not marked as live.
 */



/**
 * In-Place DFS:
 * To avoid using extra stack space during GC when memory is low, 
 * pointers are temporarily reversed to point back to the "parent" 
 * in the traversal, then restored on the way back.
 */

// =============================================================================
// SUMMARY TABLE
// =============================================================================
/**
 * | Feature         | Run-Time Stack                | Memory Heap                 |
 * |-----------------|-------------------------------|-----------------------------|
 * | Allocation      | Automatic (Function calls)    | Manual (new/delete)         |
 * | Lifetime        | Duration of function          | Until deleted or GCed       |
 * | Order           | LIFO (Last-In, First-Out)     | Arbitrary                   |
 * | Fragmentation   | No                            | Yes                         |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a custom "Free List" allocator using the First-fit strategy?
 * 2. Provide a deeper explanation of "Smart Pointers" (unique_ptr, shared_ptr) in C++?
 * 3. Demonstrate how "Pointer Tagging" can be used to optimize mark bits in GC?
 */
