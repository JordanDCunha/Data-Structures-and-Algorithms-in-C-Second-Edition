/**
 * CHAPTER 13.5: SHORTEST PATHS
 * --- DIJKSTRA'S ALGORITHM ---
 * Dijkstra's algorithm finds the shortest path from a starting source vertex
 * to all other vertices in a weighted graph with NON-NEGATIVE edge weights.
 * * CORE CONCEPT:
 * It uses a "Greedy" approach by maintaining a "cloud" of vertices for which 
 * the shortest distance is already known. In each step, it adds the nearest 
 * vertex outside the cloud to the cloud.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// Representation of a Weighted Edge
struct Edge {
    int to;
    int weight;
};

// =============================================================================
// 13.5.1: EDGE RELAXATION
// =============================================================================
/**
 * Relaxation is the process of updating the distance to a vertex 'z' if a 
 * shorter path is found through vertex 'u'.
 * * Formula: if (D[u] + weight(u, z) < D[z]) then D[z] = D[u] + weight(u, z)
 */



// =============================================================================
// 13.5.2: DIJKSTRA'S IMPLEMENTATION
// =============================================================================
/**
 * Complexity: O((n + m) log n) using an Adjacency List and a Priority Queue.
 * Space: O(n + m)
 */

typedef pair<int, int> pii; // <distance, vertex_id>

void dijkstra(int startNode, int n, const vector<list<Edge>>& adj) {
    // D[i] stores the shortest distance from startNode to i
    vector<int> D(n, 2147483647); // Initialize with "Infinity"
    D[startNode] = 0;

    // Priority Queue to store <distance, vertex>, always gives the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, startNode});

    while (!Q.empty()) {
        int d = Q.top().first;
        int u = Q.top().second;
        Q.pop();

        // If we found a longer path already in the queue, skip it
        if (d > D[u]) continue;

        // Iterate through all neighbors of u
        for (const auto& edge : adj[u]) {
            int z = edge.to;
            int weight = edge.weight;

            // --- RELAXATION STEP ---
            if (D[u] + weight < D[z]) {
                D[z] = D[u] + weight;
                Q.push({D[z], z});
            }
        }
    }

    // Output results
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << startNode << " to " << i << " is " << D[i] << endl;
    }
}



// =============================================================================
// 13.5.3: COMPARISON OF SHORTEST PATH ALGORITHMS
// =============================================================================
/**
 * | Algorithm      | Weights      | Complexity      | Notes                      |
 * |----------------|--------------|-----------------|----------------------------|
 * | BFS            | Unweighted   | O(n + m)        | Shortest path = fewest hops|
 * | Dijkstra       | Non-negative | O((n+m) log n)  | Greedy, efficient          |
 * | Bellman-Ford   | Any          | O(n * m)        | Detects negative cycles    |
 * | Floyd-Warshall | Any          | O(n^3)          | All-pairs shortest path    |
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement the Bellman-Ford algorithm to handle negative edge weights?
 * 2. Show how to reconstruct the actual path (not just the distance) using a 'predecessor' array?
 * 3. Explain the difference between Dijkstra and A* Search for pathfinding?
 */
