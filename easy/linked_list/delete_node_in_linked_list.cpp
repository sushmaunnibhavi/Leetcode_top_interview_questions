/*Question link: https://leetcode.com/problems/delete-node-in-a-linked-list/*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        /*
            1->2->3->NULL  
            
            Node 2 to be deleted
            
            Stop when curr->next->next=NULL
            curr->val =  curr->next->val
            curr->next points to NULL
            3 goes in place of 2
        */
        
        while(node->next->next!=NULL){
            node->val=node->next->val;
            node=node->next;
        }
        
        node->val=node->next->val;
        node->next=NULL;
    }
};