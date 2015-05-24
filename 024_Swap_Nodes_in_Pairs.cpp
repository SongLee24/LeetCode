class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* p = new ListNode(0);
        head = p;
        while(first!=NULL && second!=NULL) {
            ListNode* temp1 = first;
            ListNode* temp2 = second;
            if(second->next!=NULL)
                second = second->next->next;
            if(first->next!=NULL)
                first = first->next->next;
            p->next = temp2;
            p->next->next = temp1;
            p = p->next->next;
            p->next = NULL;
        }
        if(first!=NULL) {
            p->next = first;
        }
        return head->next;
    }
};