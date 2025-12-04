//BFS
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V , vector<int> adj[] ){
    int visited[V] = {0};
    vector<int> bfs_traversal;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs_traversal.push_back(node);
        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}