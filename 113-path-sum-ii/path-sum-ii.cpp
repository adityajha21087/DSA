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
class Solution {
public:
    void helper(TreeNode*root, int  a , int & t, vector<int> ans, vector<vector<int>> & ans1 ){
        if(root==NULL) return ;
        if(a==root->val && root->left==NULL && root->right==NULL ){
            ans.push_back(a);
            ans1.push_back(ans);
            a=t;
            return ;
        }
        ans.push_back(root->val);
        helper(root->left, a-root->val, t, ans,ans1);
        helper(root->right,a-root->val, t,ans,ans1);
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
       vector<int> ans;
       vector<vector< int> > ans1;
       int a= t;
       helper(root, a, t, ans, ans1);
       return ans1;
    }
};