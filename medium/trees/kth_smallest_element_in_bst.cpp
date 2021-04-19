/*Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/*/

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
    void findKthSmallest(TreeNode* root, int k,int *count,int *kth_smallest){
        if(root==NULL){
            return;
        }
        
        findKthSmallest(root->left,k,count,kth_smallest);
        *count+=1;
        if(*count==k){
            *kth_smallest=root->val;
        }
        findKthSmallest(root->right,k,count,kth_smallest);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        //inorder traversal gives nodes in ascending order
        
       int count=0,kth_smallest=0;
        findKthSmallest(root,k,&count,&kth_smallest);
        return kth_smallest;
        
    }
};

/*

Time Complexity:O(n)

*/