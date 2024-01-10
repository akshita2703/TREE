#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
     int maxDepth(TreeNode* root) {
        if(root ==0)return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(l==-1||r==-1)return -1;
        if(abs(l-r)>1)return -1;
        return 1+ max(l,r);
        
    }
    bool isBalanced(TreeNode* root) {
        int ans = maxDepth(root);
        if(ans==-1)return 0;
        else{return 1;}
        
    }
};


int main() {
    // Example usage:

    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.isBalanced(root);
    cout<<endl;

    cout << "Max path sum Result: "<<result;
   

    // Don't forget to free the allocated memory for the binary tree nodes
    // (this is a simple example, in real code you might want to use smart pointers or another memory management strategy)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}