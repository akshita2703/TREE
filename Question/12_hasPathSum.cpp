// https://leetcode.com/problems/path-sum/

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


        //         5   
        //       4    8 
        //     11   15  4  
        //   7   2        1

        // sum = 0 5 9 20 27  --- 27 == targetsum if(yes)true nhi toh false
        //       22  ----  22 same 
        //       5 8 15  --- 28
        //       5 8 4 1 -- 18    backtrack bhi krna h boss uska dhyan rkhna 





class Solution {
public:
    bool solve(TreeNode* root, int targetSum,int sum){
        if(!root)return false;
         sum+=root->val;
        if(root->left==NULL && root->right == NULL){
            if(sum==targetSum)return true;
        }
       
        bool l = solve(root->left,targetSum,sum);
        bool r = solve(root->right,targetSum,sum);
        sum-=root->val;
        return l||r;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        bool ans = solve(root,targetSum,sum);
        return ans;
        
    }
};