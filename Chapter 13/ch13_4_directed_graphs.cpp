/**
 * CHAPTER 13.4: DIRECTED GRAPHS (DIGRAPHS)
 * --- CONCEPTS ---
 * Digraphs consist of edges with a specific direction (origin -> destination).
 * * KEY TOPICS:
 * 1. Reachability: Can we get from vertex u to v via a directed path?
 * 2. Strong Connectivity: Every vertex can reach every other vertex.
 * 3. Transitive Closure: A graph G* that has an edge (u,v) if u reaches v in G.
 * 4. DAGs: Directed Acyclic Graphs (no directed cycles).
 */

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// =============================================================================
// 13.4.1: DIRECTED DFS & REACHABILITY
// =============================================================================
/**
 * Directed DFS only follows edges in their intended direction.
 * Edge Classifications in Digraph DFS:
 * - Tree Edges: Edges in the DFS tree.
 * - Back Edges: To an ancestor (indicates a cycle).
 * - Forward Edges: To a descendant.
 * - Cross Edges: To a vertex in a different subtree.
 */



// =============================================================================
// 13.4.2: TRANSITIVE CLOSURE (FLOYD-WARSHALL)
// =============================================================================
/**
 * Computes reachability for all pairs in O(n^3) time.
 * Logic: For every pair (i, j), if there is an intermediate vertex k 
 * such that i->k and k->j exist, then an edge i->j is added.
 */
void floydWarshall(int n, vector<vector<bool>>& adj) {
    // adj[i][j] is true if there is an edge from i to j
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][k] && adj[k][j]) {
                    adj[i][j] = true;
                }
            }
        }
    }
}



// =============================================================================
// 13.4.3: TOPOLOGICAL SORTING (FOR DAGs)
// =============================================================================
/**
 * Provides a linear ordering of vertices such that for every edge (u, v),
 * u comes before v. 
 * Complexity: O(n + m)
 */
struct DigraphVertex {
    int id;
    int inDegree;
    list<int> neighbors;
};

void topologicalSort(int n, vector<DigraphVertex>& vertices) {
    stack<int> S;
    for (int i = 0; i < n; i++) {
        if (vertices[i].inDegree == 0) S.push(i);
    }

    vector<int> result;
    while (!S.empty()) {
        int u = S.top(); S.pop();
        result.push_back(u);

        for (int v : vertices[u].neighbors) {
            vertices[v].inDegree--;
            if (vertices[v].inDegree == 0) {
                S.push(v);
            }
        }
    }

    if (result.size() < n) {
        cout << "Graph has a cycle! Not a DAG." << endl;
    } else {
        cout << "Topological Order: ";
        for (int id : result) cout << id << " ";
        cout << endl;
    }
}



// =============================================================================
// 13.4.4: STRONG CONNECTIVITY TEST
// =============================================================================
/**
 * Efficient O(n + m) test:
 * 1. Perform DFS from vertex s. If not all vertices reached, return false.
 * 2. Reverse all edges in G to create G_rev.
 * 3. Perform DFS from s in G_rev. If all reached, return true.
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Provide the code to reverse a Directed Graph (for strong connectivity)?
 * 2. Implement the full Floyd-Warshall algorithm with weights (all-pairs shortest path)?
 * 3. Show how to use Topological Sort for task scheduling logic?
 */
