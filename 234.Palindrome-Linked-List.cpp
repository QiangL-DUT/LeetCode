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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        for (ListNode* temp = head; temp != NULL; temp = temp->next) {
            ++len;
        }
        ListNode *right = head;
        for (int i = 0; i < (len + 1) / 2; ++i) {
            right = right->next;
        }
        right = reverseList(right);
        while (right != NULL) {
            if (right->val != head->val) {
                return false;
            }
            right = right->next;
            head = head->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = NULL;
        while (head != NULL) {
            cur = head;
            head = head->next;
            cur->next = pre;
            pre = cur;
        }
        return pre;
    }
};
