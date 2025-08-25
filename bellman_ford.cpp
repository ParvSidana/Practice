#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Bellman-Ford algorithm to find shortest paths from a source
void bellmanFord(int n, int src, const vector<tuple<int, int, int>>& edges, vector<int>& dist) {
    dist.assign(n, INT_MAX);
    dist[src] = 0;
    for (int i = 1; i < n; ++i) {
        for (const auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }
}

int main() {
    // Example graph (directed, weighted)
    // Edges: (u, v, w)
    vector<tuple<int, int, int>> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 3, 2},
        {3, 2, 3},
        {1, 2, -3}
    };
    int n = 4; // Number of vertices
    int src = 0;
    vector<int> dist;
    bellmanFord(n, src, edges, dist);
    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
