/*Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/*/

/*

Iterative approach:
Inorder->left,data,right

Take stack:
If curr element NOT NULL push into stack and go left
If curr element IS NULL pop element from stack,print,go right
Do this until stack is empty

*/

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
    vector<int> inorderTraversal(TreeNode* root) {

        
        stack<TreeNode*>st;
        
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        TreeNode *curr=root;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode *temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                curr=temp->right;
            }
        }
        return ans;
        
    }
};

/*
Time Complexity:
O(n)
*/

