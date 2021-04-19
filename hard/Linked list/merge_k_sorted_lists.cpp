/*Question Link: https://leetcode.com/problems/merge-k-sorted-lists/*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoSortedLists(ListNode *a,ListNode *b){
        if(a==NULL && b==NULL){
            return NULL;
        }
        if(a==NULL || b==NULL){
            if(a==NULL)
                return b;
            else
                return a;
        }
        
        ListNode *temp=NULL;
        
        if(a->val<b->val){
            temp=a;
            temp->next=mergeTwoSortedLists(a->next,b);
        }
        else{
            temp=b;
            temp->next=mergeTwoSortedLists(a,b->next);
        }
        
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode *ans=lists[0];
        for(int i=1;i<lists.size();i++){
            ListNode *temp=mergeTwoSortedLists(ans,lists[i]);
            ans=temp;
        }
        return ans;
    }
};