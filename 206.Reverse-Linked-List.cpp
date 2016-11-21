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

/**       Recursion
* class Solution {
* public:
*     ListNode* reverseList(ListNode* head) {
*         if ((head == NULL) || (head->next == NULL)) {
*             return head;
*         }
*         ListNode *rest = reverseList(head->next);
*         head->next->next = head;
*         head->next = NULL;
*         return rest;
*     }
* };
*/
