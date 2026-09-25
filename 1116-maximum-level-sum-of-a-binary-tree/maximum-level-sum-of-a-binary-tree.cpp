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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left), level(root->right));
    }
    void f(TreeNode*root, int curr, int level ,  int &sum ){

    if(root==NULL) return ;
    if(curr==level) {
        sum+=root->val;
        return ;
    }
    f(root->left, curr+1, level, sum);
    f(root->right, curr+1, level, sum);

    }
    int maxLevelSum(TreeNode* root) {
        int n=level(root);
        int maxi=INT_MIN;
        int ans=0;
     for(int i=1; i<=n; i++){
        int sum=0;
        f(root,1,i,sum );
         if(maxi<sum){
            maxi=sum;
            ans=i;
         }
     }
     return ans;
    }
};