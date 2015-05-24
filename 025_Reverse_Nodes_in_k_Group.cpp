class Solution {
public:
     ListNode* reverseKGroup(ListNode* head, int k) {
         if(head == NULL)
             return NULL;
         if(k==1) return head;
         ListNode* start = head;
         ListNode* end = head;
         ListNode* p = new ListNode(0);  // 头指针
         ListNode* new_head = p;
         while(true) {
            int i;
            for(i=0; i<k; ++i) {         // 向前移动k步
                if(end!=NULL)
                    end = end->next;
                else
                    break;
            }
            if(i <= k-1)                 // 不足k个，退出循环
                break;
            ListNode* q = start;         // 暂存start结点
            while(start!=end) {          // 采用"头插法"进行逆转
                ListNode* temp = start;
                start = start->next;
                temp->next = p->next;
                p->next = temp;
            }
            p = q;                       // 逆转后第一个结点在末尾，p指向末尾
            start = end;
         }
         p->next = start;
         return new_head->next;
     }
};