#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findMaxDistance(map<TreeNode<int>*,<TreeNode<int>*>&mp,TreeNode<int>* target){
    queue<TreeNode<int>*>q;
    q.push(target);
    map<TreeNode<int>*,int> vis;
    vis[target] =1;
    int maxi =0;
    while(!q.empty()){
        int sz = q.size();
        int fl =0;
        for(int i =0;i<sz;i++){
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                fl =1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                fl=1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(mp[node]&& !vis[mp[node]]){
                fl =1;
                vis[mp[node]] = 1;
                q.push(mp[node]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;
}

TreeNode<int>* bfstoMapParents(TreeNode<int>* root,map<TreeNode<int>*,TreeNode<int>*> &mp,int start){
    queue<TreeNode<int>*> q;
    q.push(root);
    TreeNode<int>*res;
    while(q.empty()){
        TreeNode<int>*node = q.front();
        if(node->val == start) res = node;
        q.pop();
        if(node->left){
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(TreeNode<int>* root,int start){
    map<TreeNode<int>*,TreeNode<int>*> mp;
    TreeNode<int>* target = bfstoMapParents(root,mp,start);
    int maxi = findMaxDistance(mp,target);
    return maxi;
}
int main(){
    return 0;
}