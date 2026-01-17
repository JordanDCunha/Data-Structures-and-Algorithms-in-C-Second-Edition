/**
 * CHAPTER 13.3: GRAPH TRAVERSALS
 * --- DEPTH-FIRST SEARCH (DFS) ---
 * DFS is a systematic way to explore a graph. It follows a path as deep 
 * as possible until it hits a "dead end," then backtracks to find 
 * unexplored edges.
 * * APPLICATIONS:
 * 1. Testing connectivity.
 * 2. Finding connected components.
 * 3. Finding paths and cycles.
 * 4. Computing spanning trees.
 * * COMPLEXITY: O(n + m) with Adjacency List, O(n^2) with Adjacency Matrix.
 */

#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

// =============================================================================
// 13.3.1: THE DECORATOR PATTERN
// =============================================================================
/**
 * The Decorator pattern allows us to attach metadata (like "visited") 
 * to vertex and edge objects without modifying their class definitions.
 */

class Object {}; // Base class for decoration values

class Decorator {
private:
    map<string, Object*> attributes;
public:
    void set(const string& key, Object* val) { attributes[key] = val; }
    Object* get(const string& key) { return attributes[key]; }
};

// =============================================================================
// 13.3.2: GENERIC DFS IMPLEMENTATION (TEMPLATE METHOD PATTERN)
// =============================================================================
/**
 * This class provides the structure for DFS. Specific logic is added by
 * overriding virtual functions in subclasses.
 */



template <typename G>
class DFS {
protected:
    typedef typename G::Vertex Vertex;
    typedef typename G::Edge Edge;

    const G& graph;
    Object *yes, *no; // Decoration markers

    // Marking Utilities
    void visit(Vertex& v) { v.set("visited", yes); }
    void unvisit(Vertex& v) { v.set("visited", no); }
    bool isVisited(Vertex& v) { return v.get("visited") == yes; }

public:
    DFS(const G& g) : graph(g), yes(new Object), no(new Object) {}

    virtual void startVisit(const Vertex& v) {}
    virtual void finishVisit(const Vertex& v) {}
    virtual void traverseDiscovery(const Edge& e, const Vertex& from) {}
    virtual void traverseBack(const Edge& e, const Vertex& from) {}
    virtual bool isDone() const { return false; }

    void dfsTraversal(Vertex& v) {
        startVisit(v);
        visit(v);
        list<Edge> incident = v.incidentEdges();
        for (auto it = incident.begin(); it != incident.end() && !isDone(); ++it) {
            Edge e = *it;
            if (!isVisited(e)) {
                visit(e);
                Vertex w = e.opposite(v);
                if (!isVisited(w)) {
                    traverseDiscovery(e, v);
                    if (!isDone()) dfsTraversal(w);
                } else {
                    traverseBack(e, v);
                }
            }
        }
        if (!isDone()) finishVisit(v);
    }
};

// =============================================================================
// 13.3.3: CONCRETE APPLICATIONS
// =============================================================================

/**
 * APPLICATION: COUNTING CONNECTED COMPONENTS
 */
template <typename G>
class Components : public DFS<G> {
public:
    Components(const G& g) : DFS<G>(g) {}
    
    int count() {
        int nComponents = 0;
        auto verts = this->graph.vertices();
        for (auto& v : verts) {
            if (!this->isVisited(v)) {
                this->dfsTraversal(v);
                nComponents++;
            }
        }
        return nComponents;
    }
};

/**
 * APPLICATION: FINDING A PATH (s -> t)
 */
template <typename G>
class FindPath : public DFS<G> {
private:
    list<typename G::Vertex> path;
    typename G::Vertex target;
    bool done;

protected:
    void startVisit(const typename G::Vertex& v) override {
        path.push_back(v);
        if (v == target) done = true;
    }
    void finishVisit(const typename G::Vertex& v) override {
        if (!done) path.pop_back();
    }
    bool isDone() const override { return done; }

public:
    FindPath(const G& g) : DFS<G>(g) {}
    list<typename G::Vertex> find(typename G::Vertex s, typename G::Vertex t) {
        path.clear(); target = t; done = false;
        this->dfsTraversal(s);
        return path;
    }
};

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement Breadth-First Search (BFS) for finding shortest paths?
 * 2. Show how to detect cycles in a Directed Graph (Digraph)?
 * 3. Explain the "Biconnected Components" algorithm?
 */
