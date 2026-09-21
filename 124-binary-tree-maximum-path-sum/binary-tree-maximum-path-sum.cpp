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

       int maxSum=INT_MIN;
    int maxPathsum(TreeNode* root) {
        if(root==NULL) return 0;
        int leftSum=maxPathsum(root->left);
        int rightSum=maxPathsum(root->right);

        int pathSum=root->val;
        if(leftSum>0) pathSum+=leftSum;
        if(rightSum>0) pathSum+=rightSum;
        maxSum=max(pathSum, maxSum);
        return root->val+max(leftSum,max(0, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        maxPathsum(root);
        return maxSum;
    }
};