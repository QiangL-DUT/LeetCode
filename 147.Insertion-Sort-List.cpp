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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        while (head != NULL) {
            ListNode *pre = &dummy;
            ListNode *cur = head;
            head = head->next;
            while ((pre->next != NULL) && (pre->next->val <= cur->val)) {
                pre = pre->next;
            }
            if (pre->next == NULL) {
                pre->next = cur;
                cur->next = NULL;
            }
            else {
                cur->next = pre->next;
                pre->next = cur;
            }
        }
        return dummy.next;
    }
};
