/*Question Link: https://leetcode.com/problems/palindrome-linked-list/*/

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
    ListNode *reverse(ListNode *second_list){
        ListNode *prev=NULL,*curr=second_list,*next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        int count_of_nodes=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count_of_nodes++;
        }
        ListNode *first_list=head,*second_list;
        if(count_of_nodes%2==0){
            ListNode *slow_ptr=head,*fast_ptr=head;
            while(fast_ptr && fast_ptr->next!=NULL){
                slow_ptr=slow_ptr->next;
                fast_ptr=fast_ptr->next->next;
            }
            
            /*
                1->2->2->1
                slow_ptr points to the second 2
            */
            
            second_list=slow_ptr;
            temp=head;
            while(temp->next!=slow_ptr){
                temp=temp->next;
            }
            temp->next=NULL;
        }
        else{
            ListNode *slow_ptr=head,*fast_ptr=head;
            while(fast_ptr && fast_ptr->next!=NULL){
                slow_ptr=slow_ptr->next;
                fast_ptr=fast_ptr->next->next;
            }
            
            /*
                1->2->1
                slow_ptr points to 2
            */
            
            second_list=slow_ptr->next;
            temp=head;
            while(temp->next!=slow_ptr){
                temp=temp->next;
            }
            temp->next=NULL;
            
        }
        
        ListNode *Second_list=reverse(second_list);
        
        while(first_list!=NULL && Second_list!=NULL){
            if(first_list->val != Second_list->val){
                return false;
            }
            first_list=first_list->next;
            Second_list=Second_list->next;
        }
        
        return true;
    }
};