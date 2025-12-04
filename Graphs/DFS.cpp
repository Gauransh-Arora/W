//DFS
#include<bits/stdc++.h>
using namespace std;

void dfs_helper(int node, vector<int> adj[], int vis[], vector<int> &dfs_traversal){
    vis[node] = 1;
    dfs_traversal.push_back(node);
    //Traverse all its neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs_helper(it, adj, vis, dfs_traversal);
        }
    }
}

vector<int> dfs(int V , vector<int> adj[] ){
    int vis[V] = {0};
    vector<int> dfs_traversal;
    int start_node = 0;
}