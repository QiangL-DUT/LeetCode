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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode *listA = headA;
        ListNode *listB = headB;
        while (listA != NULL) {
            listA = listA->next;
            ++m;
        }
        while (listB != NULL) {
            listB = listB->next;
            ++n;
        }
        listA = headA;
        listB = headB;
        while (m > n) {
            --m;
            listA = listA->next;
        }
        while (n > m) {
            --n;
            listB = listB->next;
        }
        while (n > 0) {
            if (listA == listB) {
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
            --n;
        }
        return NULL;
    }
};
