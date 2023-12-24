//https://leetcode.com/problems/diameter-of-binary-tree/description/
// diameter of tree - longest path between two nodes
 //                 - path does not need to pass via root 

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
     int maxDepth(TreeNode* root,int &maxi) {
        if(root ==NULL)return 0;
        int l = maxDepth(root->left,maxi);
        int r = maxDepth(root->right,maxi);
        maxi = max(maxi,l+r);
        return 1+ max(l,r);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
         maxDepth(root,maxi);   
         return maxi;
    }
    

};


int main() {
    // Example usage:

    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    int result = solution. diameterOfBinaryTree(root);
    cout<<endl;

    cout << "Balanced Binary Tree Result: "<<result;
   

    // Don't forget to free the allocated memory for the binary tree nodes
    // (this is a simple example, in real code you might want to use smart pointers or another memory management strategy)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

































