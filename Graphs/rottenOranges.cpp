#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int &fresh, int &minutes) {
        int n = grid.size();
        int m = grid[0].size();

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;   // rot it
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++; // increase minutes only if a new orange rotted
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        queue<pair<int,int>> q;

        // collect rotten + count fresh
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;

        bfs(grid, q, fresh, minutes);

        if (fresh > 0) return -1;
        return minutes;
    }
};
