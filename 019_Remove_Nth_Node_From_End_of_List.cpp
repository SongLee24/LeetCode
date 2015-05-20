class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = new ListNode(0);
        p->next = head;
        
        ListNode* slow = p;     // 快慢指针
        ListNode* fast = p;
        while(n--)              // fast先行n步
            fast = fast->next;
        
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        
        return p->next;
    }
};