/**
 * CHAPTER 13.6: MINIMUM SPANNING TREES (MST)
 * --- PROBLEM DEFINITION ---
 * A Spanning Tree is a subset of edges that connects all vertices in a graph 
 * without any cycles. A Minimum Spanning Tree is a spanning tree where the 
 * sum of edge weights is minimized.
 * * * CRUCIAL FACT (Proposition 13.24):
 * For any partition of vertices into two sets V1 and V2, the minimum weight 
 * edge connecting a vertex in V1 to a vertex in V2 is part of some MST.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// =============================================================================
// 13.6.1: KRUSKAL'S ALGORITHM
// =============================================================================
/**
 * Kruskal's is an edge-based greedy algorithm. 
 * Logic: Sort all edges and add the smallest edge that doesn't create a cycle.
 * Implementation: Uses Union-Find to manage connected clusters.
 * Complexity: O(m log n)
 */



struct KruskalEdge {
    int u, v, weight;
    bool operator<(const KruskalEdge& other) const { return weight < other.weight; }
};

// Simple Union-Find for Kruskal's
struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

void kruskalMST(int n, vector<KruskalEdge>& edges) {
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    vector<KruskalEdge> mst;
    
    for (auto& e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            mst.push_back(e);
            ds.unite(e.u, e.v);
        }
    }
    // Output MST edges...
}



// =============================================================================
// 13.6.2: PRIM-JARNÍK ALGORITHM
// =============================================================================
/**
 * Prim-Jarník is a vertex-based greedy algorithm (similar to Dijkstra).
 * Logic: Grow a single cloud from a starting vertex. In each step, add the 
 * cheapest edge connecting the cloud to an outside vertex.
 * Complexity: O(m log n) with a priority queue.
 */

typedef pair<int, int> pii; // <weight, vertex>

void primMST(int start, int n, const vector<vector<pii>>& adj) {
    vector<int> D(n, 2147483647); // Minimum weight to reach cloud
    vector<bool> inCloud(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> Q;

    D[start] = 0;
    Q.push({0, start});

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        if (inCloud[u]) continue;
        inCloud[u] = true;

        for (auto& edge : adj[u]) {
            int v = edge.second;
            int weight = edge.first;

            // Relaxation-like step for MST:
            // Check if edge(u,v) is cheaper than the current best way to connect v
            if (!inCloud[v] && weight < D[v]) {
                D[v] = weight;
                Q.push({D[v], v});
            }
        }
    }
}



/**
 * COMPARISON SUMMARY:
 * - Kruskal's: Generally better for sparse graphs. Simple to implement with Union-Find.
 * - Prim's: Generally better for dense graphs (especially if using Fibonacci Heaps).
 * * WOULD YOU LIKE ME TO:
 * 1. Implement a specific "Union-Find" class with Union-by-Rank for better performance?
 * 2. Show how to modify these algorithms to find a "Maximum Spanning Tree"?
 * 3. Demonstrate how MSTs are used in clustering algorithms for Data Science?
 */
