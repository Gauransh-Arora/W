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

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int currMin, int currMax) {
        if (!root) return;

        ans = max(ans, abs(root->val - currMin));
        ans = max(ans, abs(root->val - currMax));

        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);

        dfs(root->left, currMin, currMax);
        dfs(root->right, currMin, currMax);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
