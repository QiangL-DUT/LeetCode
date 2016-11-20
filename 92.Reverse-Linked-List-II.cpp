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
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        if (m == n) {
            return head;
        }
        ListNode dummy(0);
        ListNode *pre = &dummy;
        dummy.next = head;
        for (int i = 1; i < m; ++i) {
            pre = pre->next;
        }
        head = pre->next;
        ListNode *cur = head->next;
        for (int i = m; i < n; ++i) {
            ListNode *temp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = temp;
        }
        head->next = cur;
        return dummy.next;
    }
};
