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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (head != NULL) {
            if (head->val != val) {
                pre->next = head;
                pre = head;
            }
            head = head->next;
        }
        return dummy.next;
    }
};
