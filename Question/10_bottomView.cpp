

#include <bits/stdc++.h>
#include <vector>
using namespace std;
    //Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };




vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<TreeNode<int> *,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int line = it.second;
        mp[line] = node->data;
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto ch : mp){
        int vall = ch.second;
        ans.push_back(vall);
    }
    return ans;
}
