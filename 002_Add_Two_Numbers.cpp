/**
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }

    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if(l1==NULL && l2==NULL && carry==0)  // 递归终止条件
            return NULL;

        int sum = carry;  // 对应的两个位相加，并且加上进位
        if(l1!=NULL) sum += l1->val;
        if(l2!=NULL) sum += l2->val;

        ListNode* result = new ListNode(0);  // 新建一个结点
        result->val = sum%10;
        result->next = add(l1==NULL?NULL:l1->next, 
                           l2==NULL?NULL:l2->next, 
                           sum>=10?1:0);

        return result;
    }
};