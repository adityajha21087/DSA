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
    TreeNode* precessor(TreeNode*pre){
      
        pre=pre->left;
        while(pre->right){
            pre=pre->right;
        }
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root==NULL)   return NULL;
      if(root->val==key)
    {  //node has no child
      if(root->left==NULL && root->right==NULL) return NULL;
      // node has only one child
      if(root->left==NULL || root->right==NULL){
        if(root->left) return root->left;
        else return root->right;
      }
      // node has two child
      else {
        TreeNode*p=precessor(root);
        root->val=p->val;
       root->left= deleteNode(root->left,p->val);
      }}
    root->left=deleteNode(root->left,key);
    root->right=deleteNode(root->right,key);
    return root;
    }
};

// class Solution {
// public:
//    TreeNode* iop(TreeNode* root){
//     TreeNode*pre=root->left;
//     while(pre->right!=NULL){
//         pre=pre->right;
//     }
//     return pre;
//    }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//       if(root==NULL)   return NULL;
//       if(root->val==key){
//         // key is a leaf Node
//         if(root->left==NULL && root->right==NULL ) return NULL;
//         // key has one node
//         else if(root->left==NULL || root->right==NULL){
//             if(root->left !=NULL) return root->left;
//             else return root->right;
//         }
//         // key has two node
//         else {
//             // inorder preccesor
//             TreeNode*pre=iop(root);
//             root->val=pre->val;
//             root->left=deleteNode(root->left, pre->val);
//         }
//       }
//       root->left=deleteNode( root->left,  key);
//       root->right=deleteNode(root->right, key);
//       return root;
//     }
// };