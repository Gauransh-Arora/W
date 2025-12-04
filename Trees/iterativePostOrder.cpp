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

//Using 2 Stacks
vector<int> iterativePostOrder2Stack(TreeNode* root) {
    vector<int> postOrder;
    if(!root) return postOrder;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while(!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }

    while(!s2.empty()) {
        postOrder.push_back(s2.top()->val);
        s2.pop();
    }

    return postOrder;
}

//Using 1 Stack
vector<int> iterativePostOrder1Stack(TreeNode* root) {
    vector<int> postOrder;
    if(!root) return postOrder;

    stack<TreeNode*> st;
    TreeNode* current = root;

    while(current || !st.empty()) {
        if(current) {
            st.push(current);
            current = current->left;
        } else {
            TreeNode* temp = st.top()->right;
            if(!temp) {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                }
            } else {
                current = temp;
            }
        }
    }

    return postOrder;
}