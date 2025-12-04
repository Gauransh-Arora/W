#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }
    }
}

int countComponents(int V, vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(V);

    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(V, 0);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    return components;
}

