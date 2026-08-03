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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i , count=n ;
        ListNode *front = head ;
        ListNode *prev = head ;
        while(count && front!=NULL){
            front = front->next ;
            count -- ;
        }
        if(front == NULL)
         return head->next;
        while(front!=NULL && front->next!=NULL){
            front = front->next ;
            prev = prev->next ;
        }
        if(prev->next != NULL)
        prev->next = prev->next->next ;
        
        return head ;

    }
};
