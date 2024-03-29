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
    void rec(TreeNode* node, int level, vector<int>&res){
        if(node==NULL) return ;
        if(res.size()== level) res.push_back(node->val);
        rec(node->right,level+1,res); //  for left just call left recursive function first
        rec(node->left,level+1,res);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rec(root,0,res);
        return res;
        
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
    vector<int> result = solution.rightSideView(root);

   // Print the 2D vector
    for (const auto row : result) {
        
            cout << row << " ";
        cout << endl;
    }
    cout<<endl;
    
    cout<<endl;

   

    // Don't forget to free the allocated memory for the binary tree nodes
    // (this is a simple example, in real code you might want to use smart pointers or another memory management strategy)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}