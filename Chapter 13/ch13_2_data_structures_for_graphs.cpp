/**
 * CHAPTER 13.2: DATA STRUCTURES FOR GRAPHS
 * --- COMPARISON OF REPRESENTATIONS ---
 * 1. Edge List: Simplest, stores edges in one list. Inefficient for neighbor lookups.
 * 2. Adjacency List: Extends Edge List by giving each vertex its own list of incident edges.
 * 3. Adjacency Matrix: Uses a 2D array to map all possible vertex pairs. Fast for adjacency 
 * checks but consumes more space.
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// =============================================================================
// 13.2.1: THE EDGE LIST STRUCTURE
// =============================================================================
/**
 * Space: O(n + m)
 * incidentEdges(v): O(m) - Must scan all edges to find those connected to v.
 */
struct EdgeListVertex {
    int element;
    // No direct reference to incident edges
};

struct EdgeListEdge {
    int element;
    EdgeListVertex *u, *v; // References to endpoints
};



// =============================================================================
// 13.2.2: THE ADJACENCY LIST STRUCTURE
// =============================================================================
/**
 * Space: O(n + m)
 * incidentEdges(v): O(deg(v)) - Very efficient for graph traversals.
 * Most widely used representation for sparse graphs.
 */
struct AdjListEdge; // Forward declaration

struct AdjListVertex {
    int element;
    list<AdjListEdge*> incidentEdges; // Direct access to local edges
};

struct AdjListEdge {
    int element;
    AdjListVertex *u, *v;
};



// =============================================================================
// 13.2.3: THE ADJACENCY MATRIX STRUCTURE
// =============================================================================
/**
 * Space: O(n^2)
 * isAdjacentTo(u, v): O(1) - Just check matrix[u][v].
 * Best for dense graphs where m is close to n^2.
 */
class AdjacencyMatrix {
private:
    int n;
    vector<vector<bool>> matrix; // Stores true if edge exists
public:
    AdjacencyMatrix(int numVertices) : n(numVertices), matrix(n, vector<bool>(n, false)) {}

    void addEdge(int i, int j) {
        matrix[i][j] = true;
        matrix[j][i] = true; // For undirected graphs
    }

    bool isAdjacent(int i, int j) {
        return matrix[i][j];
    }
};



// =============================================================================
// PERFORMANCE SUMMARY
// =============================================================================
/**
 * | Operation        | Edge List | Adj. List      | Adj. Matrix |
 * |------------------|-----------|----------------|-------------|
 * | Space            | O(n + m)  | O(n + m)       | O(n^2)      |
 * | incidentEdges(v) | O(m)      | O(deg(v))      | O(n)        |
 * | isAdjacent(v, w) | O(m)      | O(min(dv, dw)) | O(1)        |
 * | insertVertex     | O(1)      | O(1)           | O(n^2)      |
 * | eraseVertex(v)   | O(m)      | O(deg(v))      | O(n^2)      |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a complete C++ class for the Adjacency List structure?
 * 2. Show how to convert a graph from an Adjacency Matrix to an Adjacency List?
 * 3. Explain how "Weighted Graphs" (edges with costs) change these structures?
 */
