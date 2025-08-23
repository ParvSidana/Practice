#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal on a graph
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    // Example graph (undirected)
    // 0 -- 1
    // |    |
    // 2 -- 3
    int n = 4;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2};

    vector<bool> visited(n, false);
    cout << "DFS Traversal starting from node 0: ";
    dfs(0, adj, visited); // Start DFS from node 0
    cout << endl;
    return 0;
}
