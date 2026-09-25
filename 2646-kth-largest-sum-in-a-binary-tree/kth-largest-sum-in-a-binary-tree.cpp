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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        int level=0;
        while(q.size()>0){
         int s=q.size();
         long long sum=0;
         for(int i=1; i<=s; i++ ){
            TreeNode*temp=q.front();
            q.pop();
            sum+=temp->val;
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
         }
       
         ans.push_back(sum);
        }
        int n=ans.size();
        cout<<n<<" "<<level;
        sort(ans.begin(),ans.end());
        if(k>n) return -1;
        return ans[n-k];
    }
};