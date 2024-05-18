// bfs

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr),next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void setNextPointer(TreeNode* root){
    if(root==NULL)return ;
    TreeNode* left = root;
    while(left->left!=NULL){
        TreeNode* curr = left;
        while(curr!=NULL){
            curr->left->next = curr->right;
            if(curr->next!=NULL){
                curr->right->next = curr->next->left;
            }
        curr =  curr->next;
        }
   }
}

int main(){
    

    return 0;
}