// 迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode node(0);
        ListNode* L = &node;
        L->next = NULL;
        
        while(head!=NULL)
        {
            ListNode* q = head->next;
            head->next = L->next;
            L->next = head;  
            head = q;
        }
        
        return L->next;
    }
};


// 递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* q = head->next;
        ListNode* new_head = reverseList(q);
        head->next = NULL;
        q->next = head;
        
        return new_head;
    }
};