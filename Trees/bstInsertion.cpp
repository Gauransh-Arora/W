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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

TreeNode* buildBSTfromArray(vector<int>& arr) {
    TreeNode* root = NULL;
    for (int x : arr) root = insert(root, x);
    return root;
}

TreeNode* buildBSTfromLL(ListNode* head) {
    TreeNode* root = NULL;
    while (head) {
        root = insert(root, head->val);
        head = head->next;
    }
    return root;
}

TreeNode* buildFromPost(vector<int>& post, int& idx, int minv, int maxv){
    if (idx < 0) return NULL;
    int val = post[idx];
    if (val < minv || val > maxv) return NULL;

    idx--;
    TreeNode* root = new TreeNode(val);

    root->right = buildFromPost(post, idx, val, maxv);
    root->left = buildFromPost(post, idx, minv, val);

    return root;
}

TreeNode* bstFromPostorder(vector<int>& post) {
    int idx = post.size() - 1;
    return buildFromPost(post, idx, INT_MIN, INT_MAX);
}

TreeNode* buildFromPre(vector<int>& pre, int& i, int minv, int maxv){
    if (i >= pre.size()) return NULL;
    int val = pre[i];
    if (val < minv || val > maxv) return NULL;

    i++;
    TreeNode* root = new TreeNode(val);
    root->left = buildFromPre(pre, i, minv, val);
    root->right = buildFromPre(pre, i, val, maxv);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& pre) {
    int i = 0;
    return buildFromPre(pre, i, INT_MIN, INT_MAX);
}
