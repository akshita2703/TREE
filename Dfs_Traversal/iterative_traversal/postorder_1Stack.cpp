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
        stack<TreeNode*>st;
        TreeNode* curr = root;
        TreeNode* temp;

        while(curr!=NULL||!st.empty()){

            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                temp = st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty()&&temp==st.top()->right)
                    {
                        temp=st.top(),st.pop();
                        ans.push_back(temp->val);
                    }
                    
                }
                else{
                    curr=temp;
                }
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