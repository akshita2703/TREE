
// https://leetcode.com/problems/path-sum-ii/description/

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


                //         2
                //      4     16 
                //    8   6  3   1
                //  10   8     3   2
                //     12             3  
 
                // sum 2 6 14 24   sum == targetsum agr asie toh temp ko push krdo ans m phir left call right call
                // phir backtrack temp m se last ele pop or sum mein se root val substract
                // // [2] [2 4] [2 4 8 ] [ 2 4 8 10]







class Solution {
public:
    void solve(TreeNode* root, int targetSum,vector<vector<int>>&ans , vector<int> temp,int sum){
        if(!root)return ;
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL ){
            if(sum==targetSum){
                ans.push_back(temp);
            }
        }
        solve(root->left,targetSum,ans,temp,sum);
        solve(root->right,targetSum,ans,temp,sum);
        temp.pop_back();
        sum-=root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum =0;
        solve(root,targetSum,ans,temp,sum);
        return ans; 
    }
};