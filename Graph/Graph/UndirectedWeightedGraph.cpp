#include <iostream>
#include <vector>
#include <utility> // ?? ??????? pair
#include <queue> 
using namespace std;

using namespace std;

/*
  Undirected Weighted Graph
  - Representation: adjacency list of pairs (neighbor, weight)
  - Node indices: 0 .. V-1
  - Features:
    * addEdge(u, v, w)    : add undirected weighted edge
    * removeEdge(u, v)    : remove edge between u and v (if exists)
    * hasEdge(u, v)       : check if edge exists
    * display()           : print adjacency list
    * bfs(start)          : breadth-first traversal (ignoring weights)
    * dfs(start)          : depth-first traversal (ignoring weights)
    * dijkstra(src)       : shortest paths from src (weights >= 0)
*/

class UndirectedWeightedGraph {
private:
    int V; // number of vertices
    // adjacency list: for each vertex a vector of {neighbor, weight}
    vector<vector<pair<int, double>>> adj;

public:
    // Constructor: initialize graph with V vertices
    UndirectedWeightedGraph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Add undirected weighted edge (u <-> v) with weight w
    void addEdge(int u, int v, double w) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "addEdge: invalid vertex index\n";
            return;
        }
        adj[u].push_back({ v, w });
        if (u != v) // avoid adding twice for self-loop (but still allow self-loop)
            adj[v].push_back({ u, w });
    }

    // Remove edge between u and v (all occurrences)
    void removeEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "removeEdge: invalid vertex index\n";
            return;
        }
        // remove v from adj[u]
        auto& vecu = adj[u];
        vecu.erase(remove_if(vecu.begin(), vecu.end(),
            [&](const pair<int, double>& p) { return p.first == v; }),
            vecu.end());
        // remove u from adj[v]
        auto& vecv = adj[v];
        vecv.erase(remove_if(vecv.begin(), vecv.end(),
            [&](const pair<int, double>& p) { return p.first == u; }),
            vecv.end());
    }

    // Check if edge (u, v) exists (returns true if any entry found)
    bool hasEdge(int u, int v) const {
        if (u < 0 || u >= V || v < 0 || v >= V) return false;
        for (const auto& p : adj[u]) if (p.first == v) return true;
        return false;
    }

    // Display adjacency list with weights
    void display() const {
        cout << "Graph adjacency list (vertex : (neighbor,weight) ... )\n";
        for (int i = 0; i < V; ++i) {
            cout << i << " : ";
            for (const auto& p : adj[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << "\n";
        }
    }

    // BFS (unweighted traversal) starting from s
    void bfs(int s) const {
        if (s < 0 || s >= V) { cout << "bfs: invalid start\n"; return; }
        vector<int> vis(V, 0);
        queue<int> q;
        q.push(s); vis[s] = 1;
        cout << "BFS from " << s << " : ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (auto& p : adj[u]) {
                int v = p.first;
                if (!vis[v]) { vis[v] = 1; q.push(v); }
            }
        }
        cout << "\n";
    }

    // DFS (recursive) helper
    void dfsUtil(int u, vector<int>& vis) const {
        vis[u] = 1;
        cout << u << " ";
        for (auto& p : adj[u]) {
            int v = p.first;
            if (!vis[v]) dfsUtil(v, vis);
        }
    }

    // DFS starting from s (unweighted traversal)
    void dfs(int s) const {
        if (s < 0 || s >= V) { cout << "dfs: invalid start\n"; return; }
        vector<int> vis(V, 0);
        cout << "DFS from " << s << " : ";
        dfsUtil(s, vis);
        cout << "\n";
    }

    // Dijkstra's algorithm: returns vector of distances from src.
    // Assumes non-negative weights.
    vector<double> dijkstra(int src) const {
        const double INF = numeric_limits<double>::infinity();
        vector<double> dist(V, INF);
        if (src < 0 || src >= V) return dist;

        // min-heap of pair (distance, vertex)
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        dist[src] = 0.0;
        pq.push({ 0.0, src });

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; // stale entry

            for (auto& p : adj[u]) {
                int v = p.first;
                double w = p.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({ dist[v], v });
                }
            }
        }
        return dist;
    }

    // Utility: print distances nicely
    static void printDistances(const vector<double>& dist, int src) {
        cout << "Shortest distances from " << src << ":\n";
        for (int i = 0; i < (int)dist.size(); ++i) {
            cout << "  to " << i << " = ";
            if (isfinite(dist[i])) cout << dist[i];
            else cout << "INF";
            cout << "\n";
        }
    }
};

// =======================
// Example main
// =======================
int main() {
    // Create graph with 10 vertices (0..9)
    UndirectedWeightedGraph g(10);

    // Add weighted edges
    g.addEdge(0, 1, 4.0);
    g.addEdge(0, 7, 8.0);
    g.addEdge(1, 7, 11.0);
    g.addEdge(1, 2, 8.0);
    g.addEdge(7, 8, 7.0);
    g.addEdge(7, 6, 1.0);
    g.addEdge(2, 8, 2.0);
    g.addEdge(8, 6, 6.0);
    g.addEdge(2, 3, 7.0);
    g.addEdge(2, 5, 4.0);
    g.addEdge(6, 5, 2.0);
    g.addEdge(3, 5, 14.0);
    g.addEdge(3, 4, 9.0);
    g.addEdge(5, 4, 10.0);

    // Display adjacency list
    g.display();

    // Check existence of an edge
    cout << "\nHas edge 0-1? " << (g.hasEdge(0, 1) ? "Yes" : "No") << "\n";
    cout << "Has edge 0-2? " << (g.hasEdge(0, 2) ? "Yes" : "No") << "\n";

    // BFS / DFS examples
    cout << "\n";
    g.bfs(0);
    g.dfs(0);

    // Dijkstra from source 0
    cout << "\n";
    auto dist = g.dijkstra(0);
    UndirectedWeightedGraph::printDistances(dist, 0);

    // Remove an edge and show update
    cout << "\nRemoving edge 1-2 and showing adjacency list\n";
    g.removeEdge(1, 2);
    g.display();
    cout << "Has edge 1-2? " << (g.hasEdge(1, 2) ? "Yes" : "No") << "\n";

    return 0;
}
