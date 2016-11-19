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
        ListNode newHead(0);
        ListNode* pre_pre = &newHead;
        ListNode* pre = head;
        ListNode* cur = head->next;
        bool flag_same = false;
        while(cur != NULL) {
            if (cur->val != pre->val) {
                if (flag_same == false) {
                    pre_pre->next = pre;
                    pre_pre = pre;
                }
                else {
                    flag_same = false;
                }
                pre = cur;
            }
            else {
                flag_same = true;
            }
            cur = cur->next;
        }
        if (flag_same == true) {
            pre_pre->next = NULL;
        }
        else {
            pre_pre->next = pre;
        }
        return newHead.next;
    }
};
