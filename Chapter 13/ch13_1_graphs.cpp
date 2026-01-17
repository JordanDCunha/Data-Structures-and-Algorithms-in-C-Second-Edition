/**
 * CHAPTER 13: GRAPHS
 * --- THE CONCEPT ---
 * A graph G = (V, E) is a mathematical structure consisting of a set of 
 * vertices (V) and a collection of edges (E) that connect pairs of vertices.
 * * Key Definitions:
 * - Directed Graph (Digraph): Edges have a specific direction (origin -> destination).
 * - Undirected Graph: Edges represent symmetric relationships (no direction).
 * - Simple Graph: No self-loops (vertex to itself) and no parallel edges.
 * - Degree: The number of edges incident on a vertex.
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// =============================================================================
// 13.1.1: GRAPH TERMINOLOGY & PROPERTIES
// =============================================================================

/**
 * PROPERTY SUMMARIES:
 * 1. Sum of Degrees (Undirected): Σ deg(v) = 2m
 * 2. Sum of Degrees (Directed): Σ indeg(v) = Σ outdeg(v) = m
 * 3. Max Edges (Simple Undirected): m <= n(n-1)/2
 * 4. Max Edges (Simple Directed): m <= n(n-1)
 */



// =============================================================================
// 13.1.2: GRAPH ADT (ABSTRACT DATA TYPE)
// =============================================================================

/**
 * The Graph ADT represents vertices and edges as positions.
 * Below is a structural outline based on the STL-style interface described.
 */

class Vertex {
public:
    // operator*() returns the element (e.g., airport code "LAX")
    // incidentEdges() returns list of connected edges
    // isAdjacentTo(v) checks if there is an edge to v
};

class Edge {
public:
    // endVertices() returns the pair of vertices
    // opposite(v) given one endpoint, returns the other
    // isIncidentOn(v) checks if vertex v is an endpoint of this edge
};



// =============================================================================
// 13.1.3: SUBGRAPHS AND CONNECTIVITY
// =============================================================================
/**
 * - Path: Sequence of alternating vertices and edges.
 * - Cycle: A path that starts and ends at the same vertex.
 * - Connected: A path exists between every pair of vertices.
 * - Tree (Free Tree): A connected graph with no cycles (m = n - 1).
 * - Forest: A graph with no cycles (a collection of trees).
 * - Spanning Tree: A subgraph that includes all vertices and is a tree.
 */



/**
 * C++ Interface Example for a Graph:
 */
template <typename V, typename E>
class Graph {
public:
    typedef list<Vertex> VertexList;
    typedef list<Edge> EdgeList;

    // Accessors
    VertexList vertices() const;
    EdgeList edges() const;

    // Mutators
    Vertex insertVertex(const V& x);
    Edge insertEdge(Vertex v, Vertex w, const E& x);
    void eraseVertex(Vertex v);
    void eraseEdge(Edge e);
};

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement the "Adjacency List" data structure for this ADT?
 * 2. Discuss Section 13.2: Graph Traversal (Breadth-First vs Depth-First Search)?
 * 3. Show how to represent a "Mixed Graph" (one-way and two-way streets) in C++?
 */
