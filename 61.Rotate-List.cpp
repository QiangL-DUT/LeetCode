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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode* newHead = head;
        ListNode* cur = head;
        ListNode* last;
        int n = 0;
        while(cur != NULL) {
            last = cur;
            cur = cur->next;
            ++n;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        ListNode* pre;
        for (int i = n; i > k; --i) {
            pre = newHead;
            newHead = newHead->next;
        }
        pre->next = NULL;
        last->next = head;
        return newHead;
    }
};
