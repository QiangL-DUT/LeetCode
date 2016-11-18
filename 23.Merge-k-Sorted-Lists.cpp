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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        Heap.resize(lists.size());
        int n = 0;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                Heap[n++] = lists[i];
            }
        }
        if (n == 0) return NULL;
        if (n == 1) return Heap[0];
        BuildMinHeap(Heap, n);
        ListNode* result = Heap[0];
        ListNode* cur = result;
        while (n > 1) {
            if (Heap[0]->next != NULL) {
                Heap[0] = Heap[0]->next;
            }
            else {
                Heap[0] = Heap[--n];
            }
            MinHeapify(Heap, n, 0);
            cur->next = Heap[0];
            cur = cur->next;
        }
        return result;
    }
private:
    void MinHeapify(vector<ListNode*>& Heap, int n, int p) {
        int left = 2 * p + 1;
        int right = 2 * p + 2;
        int curIndex = p;
        if ((left < n) && (Heap[left]->val < Heap[curIndex]->val)) {
            curIndex = left;
        }
        if ((right < n) && (Heap[right]->val < Heap[curIndex]->val)) {
            curIndex = right;
        }
        if (curIndex != p) {
            ListNode* temp = Heap[p];
            Heap[p] = Heap[curIndex];
            Heap[curIndex] = temp;
            MinHeapify(Heap, n, curIndex);
        }
    }
    void BuildMinHeap(vector<ListNode*>& Heap, int n) {
        for (int i = (n - 1) / 2; i >= 0; --i) {
            MinHeapify(Heap, n, i);
        }
    }
    vector<ListNode*> Heap;
};
