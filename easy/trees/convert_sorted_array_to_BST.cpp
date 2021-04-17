/*Question link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/*/

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
    TreeNode* convertArrayToBst(vector<int>& nums,int low,int high){
        if(low>high){
            return NULL;
        }
        
        int mid=low+(high-low)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=convertArrayToBst(nums,low,mid-1);
        root->right=convertArrayToBst(nums,mid+1,high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
     
        TreeNode *root=convertArrayToBst(nums,0,nums.size()-1);
        
        return root;
    }
};

/*

Time Complexity: O(n)

*/