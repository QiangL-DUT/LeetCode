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
    ListNode* partition(ListNode *head, int x) {
        ListNode smaller_head(0);
        ListNode larger_head(0);
        ListNode *smaller_tail = &smaller_head;
        ListNode *larger_tail = &larger_head;
        while (head != NULL) {
            if (head->val < x) {
                smaller_tail->next = head;
                smaller_tail = head;
            }
            else {
                larger_tail->next = head;
                larger_tail = head;
            }
            head = head->next;
        }
        smaller_tail->next = larger_head.next;
        larger_tail->next = NULL;
        return smaller_head.next;
    }
};
