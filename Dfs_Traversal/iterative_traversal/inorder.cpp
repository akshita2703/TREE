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
    

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root ==NULL)return ans;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else {
                if(st.empty()==true)break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }  
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
    vector<int> result = solution.inorderTraversal(root);
    cout<<endl;

    cout << "inorder Traversal Result: ";
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