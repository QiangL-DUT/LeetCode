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
    ListNode* sortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            ++n;
        }
        return sortList(head, n);
    }
private:
    ListNode* sortList(ListNode *head, int n) {
        if (n == 1) {
            head->next = NULL;
            return head;
        }
        int k = n / 2;
        ListNode *mid = head;
        for (int i = 0; i < k; ++i) {
            mid = mid->next;
        }
        ListNode *sort_pre = sortList(head, k);
        ListNode *sort_next = sortList(mid, n - k);
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while ((sort_pre != NULL) && (sort_next != NULL)) {
            if (sort_pre->val < sort_next->val) {
                tail->next = sort_pre;
                tail = sort_pre;
                sort_pre = sort_pre->next;
            }
            else {
                tail->next = sort_next;
                tail = sort_next;
                sort_next = sort_next->next;
            }
        }
        tail->next = (sort_pre != NULL) ? sort_pre : sort_next;
        return dummy.next;
    }
};
