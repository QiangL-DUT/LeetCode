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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* result;
        if (l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        }
        else {
            result = l2;
            l2 = l2->next;
        }
        ListNode* cur = result;
        while ((l1 != NULL) && (l2 != NULL)) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL) {
            cur->next = l1;
        }
        else {
            cur->next = l2;
        }
        return result;
    }
};
