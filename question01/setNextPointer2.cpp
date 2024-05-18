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

void setNextPointer(TreeNode* left,TreeNode* right)
{
    if(left==NULL)return ;
    left->next = right;
    setNextPointer(left->left,left->right);
    setNextPointer(left->right,right->left);
    setNextPointer(right->left,right->right);

}

int main(){
    return 0;
}