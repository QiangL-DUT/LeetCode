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
    ListNode* swapPairs(ListNode* head) {
        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }
        ListNode* newHead = head->next;
        ListNode* newTail = head;
        head = head->next->next;
        ListNode* p;
        newHead->next = newTail;
        while (head) {
            if(head->next) {
                p = head->next->next;
                newTail->next = head->next;
                head->next->next = head;
                newTail = head;
                head = p;
            }
            else {
                newTail->next = head;
                break;
            }
        }
        if (!head) {
            newTail->next = NULL;
        }
        return newHead;
    }
};
