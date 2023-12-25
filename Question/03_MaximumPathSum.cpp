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
       int f(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int leftSum = max(0,f(root->left,maxi));
        int rightSum = max(0,f(root->right,maxi));
        maxi = max(maxi,root->val+leftSum + rightSum);
        return root->val+ max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        f(root,maxi);
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
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.maxPathSum(root);
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