
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
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(TreeNode *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode * node = it.first;
            int line = it.second;
            if(mp.find(line)==mp.end()) mp[line]=node->val; // doesn't exist
            if(node->left!=NULL){
                q.push({node->left,line-1});
            }
            if(node->right!=nullptr){
                q.push({node->right,line+1});
            }
            
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
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
    vector<int> result = solution.topView(root);

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