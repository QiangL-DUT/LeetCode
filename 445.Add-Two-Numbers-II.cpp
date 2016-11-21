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
        ListNode dummy(0);
        ListNode *result = &dummy;
        int len1 = 0, len2 = 0;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        for (;((cur1 != NULL) || (cur2 != NULL));) {
            if (cur1 != NULL) {
                ++len1;
                cur1 = cur1->next;
            }
            if (cur2 != NULL) {
                ++len2;
                cur2 = cur2->next;
            }
            result->next= new ListNode(0);
            result = result->next;
        }
        int carry = addTwoList(dummy.next, l1, len1, l2, len2);
        if (carry == 1) {
            ListNode *temp = new ListNode(carry);
            temp->next = dummy.next;
            dummy.next = temp;
        }
        return dummy.next;
    }
private:
    int addTwoList(ListNode *result, ListNode *l1, int len1, ListNode *l2, int len2) {
        if (result == NULL) {
            return 0;
        }
        int carry = 0;
        int sum = 0;
        if (len1 > len2) {
            carry = addTwoList(result->next, l1->next, len1 - 1, l2, len2);
            sum = l1->val + carry;
        }
        else if (len1 == len2) {
            carry = addTwoList(result->next, l1->next, len1 - 1, l2->next, len2 - 1);
            sum = l1->val + l2->val + carry;
        }
        else if (len1 < len2){
            carry = addTwoList(result->next, l1, len1, l2->next, len2 - 1);
            sum = l2->val + carry;
        }
        result->val = sum % 10;
        return sum / 10;
    }
};
