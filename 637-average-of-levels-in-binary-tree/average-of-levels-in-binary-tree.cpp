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
    int level(TreeNode*root){
        if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
    }

    void f(TreeNode*root, int  curr, int level ,long long  &sum, long long & count){

        if(root==NULL) return ;
        if(curr==level) {
           sum+=root->val;
           count++;
            return ;
        }
        f(root->left, curr+1, level, sum, count);
        f(root->right,curr+1, level, sum, count);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int n=level(root);
        vector<double> ans;
       for(int i=1; i<=n; i++)
       { long long  sum=0;
        long long count=0;
        f(root, 1, i, sum,count) ;
        double x=double(sum);
        double y=double(count);

        ans.push_back(x/y);
        }

       return ans;
    }
};