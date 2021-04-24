/*Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==headB){
            return headA;
        }
        int count_of_nodes_in_a=0,count_of_nodes_in_b=0;
        
        ListNode *tempA=headA,*tempB=headB;
        
        while(tempA!=NULL){
            count_of_nodes_in_a++;
            tempA=tempA->next;
        }
        
        while(tempB!=NULL){
            count_of_nodes_in_b++;
            tempB=tempB->next;
        }
        ListNode *dummyA=new ListNode(0);
        dummyA->next=headA;
        ListNode *dummyB=new ListNode(0);
        dummyB->next=headB;
        //Traverse linked list till both have equal number of nodes
        if(count_of_nodes_in_a>count_of_nodes_in_b){
           
            
            while(count_of_nodes_in_a!=count_of_nodes_in_b){
                count_of_nodes_in_a--;
                dummyA=dummyA->next;
            }
            headA=dummyA->next;
            
        }
        else if(count_of_nodes_in_a<count_of_nodes_in_b){
            
            while(count_of_nodes_in_a!=count_of_nodes_in_b){
                count_of_nodes_in_b--;
                dummyB=dummyB->next;
            }
            headB=dummyB->next;
            
        }
        
        while(dummyA!=NULL && dummyB!=NULL){
            if(dummyA->next==dummyB->next){
                return dummyA->next;
            }
            dummyA=dummyA->next;
            dummyB=dummyB->next;
        }
        
        return NULL;
    }
};