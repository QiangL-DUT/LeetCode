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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode dummy_odd(0), dummy_even(0);
        ListNode *tail_odd = &dummy_odd;
        ListNode *tail_even = &dummy_even;
        ListNode *cur = head;
        while (cur != NULL) {
            tail_odd->next= cur;
            tail_odd = cur;
            cur = cur->next;
            if (cur != NULL) {
                tail_even->next = cur;
                tail_even = cur;
                cur = cur->next;
            }
            else {
                break;
            }
        }
        tail_even->next = NULL;
        tail_odd->next= dummy_even.next;
        return head;
    }
};
