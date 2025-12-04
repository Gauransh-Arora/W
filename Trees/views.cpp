#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  
};

void rightDFS(TreeNode* node, int level, vector<int>& ans) {
    if (!node) return;

    // First time reaching this level → add to result
    if (level == ans.size())
        ans.push_back(node->val);

    rightDFS(node->right, level + 1, ans);
    rightDFS(node->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rightDFS(root, 0, ans);
    return ans;
}

void leftDFS(TreeNode* node, int level, vector<int>& ans) {
    if (!node) return;

    // First node seen at this level
    if (level == ans.size())
        ans.push_back(node->val);

    leftDFS(node->left, level + 1, ans);
    leftDFS(node->right, level + 1, ans);
}

vector<int> leftSideView(TreeNode* root) {
    vector<int> ans;
    leftDFS(root, 0, ans);
    return ans;
}

vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    // HD → node value
    map<int, int> mp;

    // Node + its horizontal distance
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Store only the FIRST node seen at this horizontal distance
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->val;
        }

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Extract top view from leftmost HD to rightmost HD
    for (auto &p : mp) {
        ans.push_back(p.second);
    }

    return ans;
}
