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

/**       Recursion
* class Solution {
* public:
*     ListNode* reverseList(ListNode* head) {
*         if ((head == NULL) || (head->next == NULL)) {
*             return head;
*         }
*         ListNode *tail = head->next;
*         ListNode *rest = reverseList(head->next);
*         head->next = NULL;
*         tail->next = head;
*         return rest;
*     }
* };
*/
