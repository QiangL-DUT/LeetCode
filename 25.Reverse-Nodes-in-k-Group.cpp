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
    ListNode* reverseKGroup(ListNode *head, int k) {
        if ((head == NULL) || (k == 1)) {
            return head;
        }
        ListNode dummy(0);
        ListNode *last_tail = &dummy;
        ListNode *cur_head, *cur_tail;
        while(head != NULL) {
            cur_head = head;
            for (int i = 1; ((i < k) && (head != NULL)); ++i) {
                head = head->next;
            }
            if (head == NULL) {
                last_tail->next = cur_head;
                break;
            }
            else if (head->next == NULL) {
                last_tail->next = head;
                reverseList(cur_head, k);
                cur_head->next = NULL;
                break;
            }
            else {
                cur_tail = head;
                head = head->next;
                reverseList(cur_head, k);
                last_tail->next = cur_tail;
                last_tail = cur_head;
            }
        }
        return dummy.next;
    }
private:
    void reverseList(ListNode *head, int k) {
        ListNode *pre = head;
        ListNode *temp;
        head = head->next;
        for (int i = 1; i < k; ++i) {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
    }
};
