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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if(l1 == NULL && l2 == NULL) {
            if (carry) {
                return new ListNode(1);
            }
            else {
                return NULL;
            }
        }
        int a = 0, b = 0;
        if (l1) {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            b = l2->val;
            l2 = l2->next;
        }
        int temp = a + b + carry;
        ListNode* node = new ListNode(temp % 10);
        node->next = addTwoNumbers(l1, l2, temp/10);
        return node;
    }
};
