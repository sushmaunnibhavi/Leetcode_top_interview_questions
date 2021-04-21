/*Question Link: https://leetcode.com/problems/symmetric-tree/*/

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
    bool checkSymmetric(TreeNode *left_subtree,TreeNode *right_subtree){
        if(left_subtree==NULL && right_subtree==NULL){
            return true;
        }
        
        if(left_subtree==NULL || right_subtree==NULL){
            return false;
        }
        
        if(left_subtree->val != right_subtree->val){
            return false;
        }
        
        return (checkSymmetric(left_subtree->left,right_subtree->right) && checkSymmetric(left_subtree->right,right_subtree->left));
    }
    bool isSymmetric(TreeNode* root) {
        bool symmetric=checkSymmetric(root->left,root->right);
        
        return symmetric;
    }
};