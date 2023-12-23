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
    

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root ==NULL)return ans;
        stack<TreeNode*>st,st2;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            st2.push(root);
             if(root->left!=NULL){
                st.push(root->left);
            }
            if(root->right!=NULL){
                st.push(root->right);
            }
           
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
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
    vector<int> result = solution.postorderTraversal(root);
    cout<<endl;

    cout << "postorder Traversal Result: ";
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