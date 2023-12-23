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
    

    vector<int> preInPostorderTraversal(TreeNode* root) {
      stack<pair<TreeNode*,int>> st;
      st.push({root,1});
      vector<int> pre,in , post;
      if(root==NULL)return post;
      while(!st.empty()){
        auto it = st.top();
        st.pop();
        // pre -->  ++ -->left
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }

        }
         // in -->  ++ -->right
        else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right, 1}); 
            }

        }
        else{
            post.push_back(it.first->val);
        }
      }
      return post;

        
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
    vector<int> result = solution.preInPostorderTraversal(root);
    cout<<endl;

    cout << "preorder Traversal Result: ";
    for (int val : result) {
        cout << val << " ";
    }

    // Don't forget to free the allocated memory for the binary tree nodes
    // (this is a simple example, in real code you might want to use smart pointers or another memory management strategy)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}