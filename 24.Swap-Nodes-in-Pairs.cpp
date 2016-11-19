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
        ListNode headNode(0);
        ListNode* preTail = &headNode;
        ListNode* nextHead = head;
        while (true) {
            if ((nextHead == NULL) || (nextHead->next == NULL)) {
                preTail->next = nextHead;
                return headNode.next;
            }
            ListNode* temp = nextHead->next->next;
            preTail->next = nextHead->next;
            nextHead->next->next = nextHead;
            preTail = nextHead;
            nextHead = temp;
        }
    }
};
