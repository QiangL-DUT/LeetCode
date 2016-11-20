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
    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }
        int n = 0;
        for (ListNode *temp = head; temp != NULL; temp = temp->next) {
            ++n;
        }
        ListNode *tail = head;
        for (int i = 0; i < (n - 1) / 2; ++i) {
            tail = tail->next;
        }
        ListNode *right = reverseList(tail->next);
        ListNode *left = head;
        tail->next = NULL;
        ListNode dummy(0);
        tail = &dummy;
        while (right != NULL) {
            tail->next = left;
            tail = tail->next;
            left = left->next;
            tail->next = right;
            tail = tail->next;
            right = right->next;
        }
        tail->next = left;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (head != NULL) {
            ListNode *cur = head;
            head = head->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        return dummy.next;
    }
};
