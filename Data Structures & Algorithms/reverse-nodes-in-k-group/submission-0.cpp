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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* first = head ;
        ListNode* last = head ;
        ListNode* nhead ;
        int count = 0 ;
        while(count<=k && last!=NULL){
            last=last->next ;
            count++ ;
        }
        if(count<k && last == NULL)
        return head ;
        else{
                ListNode* prev = nullptr;
                ListNode* curr = head;
                count = 0 ;
        while(count<k) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count ++ ;
        }
            nhead = prev ;
            first ->next = reverseKGroup(curr , k);
        }
        return nhead ;
        
    }
};
