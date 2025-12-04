#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* treeMinimum(Node* x) {
    while (x->left != NULL)
        x = x->left;
    return x;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node found: handle 3 cases

        // Case 1: no left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: no right child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: two children
        Node* temp = treeMinimum(root->right); // successor
        root->key = temp->key;                 // replace value
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}
