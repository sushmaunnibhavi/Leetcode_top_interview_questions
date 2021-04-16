/*Question link: https://leetcode.com/problems/maximum-depth-of-binary-tree/*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        return 1+max(maxDepth(root->right),maxDepth(root->left));
    }
};

/*

Time Complexity:
O(n) where n is number of nodes

*/