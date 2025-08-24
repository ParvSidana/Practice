#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(int start, const vector<vector<pair<int, int>>> &adj, vector<int> &dist)
{
    int n = adj.size();
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    // Example graph (directed, weighted)
    // 0 --(1)--> 1
    // |         |
    //(4)      (2)
    // |         |
    // 2 <---(3)-- 3
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 4});
    adj[1].push_back({3, 2});
    adj[3].push_back({2, 3});

    vector<int> dist;
    dijkstra(0, adj, dist); // Start Dijkstra from node 0
    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
