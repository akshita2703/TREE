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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
    void addLeft(TreeNode* root,vector<int>&res){
        TreeNode *cur = root->left;
        while(cur){
            if(!isLeaf(cur))res.push_back(cur->val);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
     void addRight(TreeNode* root,vector<int>&res){
        TreeNode *cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur))temp.push_back(cur->val);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for(int i =temp.size()-1;i>=0;--i){
            res.push_back(temp[i]);
        }
    }
    void addLeaves(TreeNode*root , vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->val);
            return;
        }
        if(root->left)addLeaves(root->left,res);
        if(root->right)addLeaves(root->right,res);
    }
public:
    vector<int> printBoundary(TreeNode*root){
        vector<int> res;
        if(!root)return res;
        if(!isLeaf(root))res.push_back(root->val);
        addLeft(root,res);
        addLeaves(root,res);
        addRight(root,res);
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
    vector<int> result = solution.printBoundary(root);

 
        for (int element : result) {
            cout << element << " ";
        }
        cout << endl;
    
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