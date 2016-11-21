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
        int len = 0;
        for (ListNode *temp = head; temp != NULL; temp = temp->next) {
            ++len;
        }
        ListNode *mid = head;
        for (int i = 0; i < (len - 1) / 2; ++i) {
            mid = mid->next;
        }
        ListNode *right = reverseList(mid->next);
        ListNode *left = head;
        mid->next = NULL;
        ListNode dummy(0);
        ListNode *tail = &dummy;
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
        ListNode *pre = NULL;
        while (head != NULL) {
            ListNode *cur = head;
            head = head->next;
            cur->next = pre;
            pre = cur;
        }
        return pre;
    }
};
