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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1 = new ListNode(-1);
        ListNode *list2 = new ListNode(-1);
        // reverse l1
        ListNode *cur = l1;
        while(cur) {
            ListNode *node = new ListNode(cur->val);
            node->next = list1->next;
            list1->next = node;
            cur = cur->next;
        }
        //reverse l2
        cur = l2;
        while(cur) {
            ListNode *node = new ListNode(cur->val);
            node->next = list2->next;
            list2->next = node;
            cur = cur->next;
        }
        //add
        ListNode *p = list1->next;
        ListNode *q = list2->next;
        ListNode *res = new ListNode(-1);
        int jinwei = 0;
        while(p && q) {
            int addresult = p->val + q->val + jinwei;
            jinwei = addresult / 10;
            ListNode *node = new ListNode(addresult%10);
            node->next = res->next;
            res->next = node;
            p = p->next;
            q = q->next;
        }
        while(p) {
            ListNode *node = new ListNode((p->val + jinwei)%10);
            node->next = res->next;
            res->next = node;
            jinwei = (p->val+jinwei)/10;
            p = p->next;
        }
        while(q) {
            ListNode *node = new ListNode((q->val + jinwei)%10);
            node->next = res->next;
            res->next = node;
            jinwei = (q->val+jinwei)/10;
            q = q->next;
        }
        if(jinwei) {
            ListNode *node = new ListNode(jinwei);
            node->next = res->next;
            res->next = node;
        }
        return res->next;
    }
};
