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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != NULL) {
            if (cur->val != pre->val) {
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        pre->next = NULL;
        return head;
    }
};
