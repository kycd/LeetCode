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
    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }
    
    ListNode* reverse(ListNode* head, ListNode* rList) {
        if(head == NULL)
            return rList;
        
        ListNode* Next = head->next;
        head->next = rList;
        return reverse(Next, head);
    }
};