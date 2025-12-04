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

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        TreeNode* node = NULL;

        while (size--) {
            node = q.front(); 
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(node->val); // last node of this level
    }

    return ans;
}

vector<int> leftSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (i == 0) 
                ans.push_back(node->val); // first node of level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
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
