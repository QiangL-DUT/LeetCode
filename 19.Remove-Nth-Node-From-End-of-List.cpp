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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* removed;
        for (int i = 1; i <= n; ++i) {
            cur = cur->next;
        }
        if (cur == NULL) {
            removed = head;
            head = head->next;
        }
        else {
            ListNode* pre_removed = head;
            cur = cur->next;
            while (cur != NULL) {
                cur = cur->next;
                pre_removed = pre_removed->next;
            }
            removed = pre_removed->next;
            pre_removed->next = pre_removed->next->next;
        }
        delete removed;
        return head;
    }
};
