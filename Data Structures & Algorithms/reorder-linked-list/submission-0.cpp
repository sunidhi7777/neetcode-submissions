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
    ListNode* reverseList(ListNode* head) {
         ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextNode;
        }

        return prev;
    }
    ListNode* mergelist(ListNode* h1 , ListNode* h2){
        if(h1 == NULL || h2 == NULL){
            return h1 == NULL ? h2 : h1;
        }
        ListNode* second1 = h1->next ;
        ListNode* second2 = h2->next ;
        h1->next = h2 ;
        h2->next = mergelist(second1 , second2);
        return h1 ;
    }
    void reorderList(ListNode* head) {
        ListNode *slow=head , *fast = head ;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next ;
            slow = slow-> next ; 
        }
        ListNode *seclist = slow-> next ;
        slow->next = NULL ;
        seclist = reverseList(seclist);
        mergelist(head , seclist);
    }
};
