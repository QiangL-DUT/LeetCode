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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);    
    }
private:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if ((l1 == NULL) && (l2 == NULL)) {
            if (carry == 1) {
                return new ListNode(1);
            }
            else {
                return NULL;
            }
        }
        ListNode *node = new ListNode(carry);
        if (l1 != NULL) {
            node->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            node->val += l2->val;
            l2 = l2->next;
        }
        carry = node->val / 10;
        node->val %= 10;
        node->next = addTwoNumbers(l1, l2, carry);
        return node;
    }
};
