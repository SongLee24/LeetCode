class cmp {
 public:
     bool operator()(ListNode* p1, ListNode* p2) const {
        return p1->val > p2->val;
     }
 }; 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>::iterator beg = lists.begin();
        for( ; beg!=lists.end(); ) {    // 先移除lists中的空链表
            if(*beg == NULL)
                beg = lists.erase(beg);
            else
                ++beg;
        }

        if(lists.empty())               // 如果为空，返回NULL
            return NULL;

        priority_queue<ListNode*,vector<ListNode*>,cmp> q(lists.begin(), lists.end());  // 优先级队列
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(!q.empty()) {
            p->next = q.top();
            p = p->next;
            q.pop();
            if(p->next != NULL)
                q.push(p->next);
        }
        return head->next;
    }
};