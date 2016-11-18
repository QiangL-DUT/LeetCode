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
        heap.resize(lists.size());
        int n = 0;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                heap[n++] = lists[i];
            }
        }
        if (n == 0) return NULL;
        if (n == 1) return heap[0];
        BuildMinHeap(heap, n);
        ListNode* result = heap[0];
        ListNode* cur = result;
        while (n > 1) {
            if (heap[0]->next != NULL) {
                heap[0] = heap[0]->next;
            }
            else {
                heap[0] = heap[--n];
            }
            MinHeapify(heap, n, 0);
            cur->next = heap[0];
            cur = cur->next;
        }
        return result;
    }
private:
    void MinHeapify(vector<ListNode*>& heap, int n, int p) {
        int left = 2 * p + 1;
        int right = 2 * p + 2;
        int curIndex = p;
        if ((left < n) && (heap[left]->val < heap[curIndex]->val)) {
            curIndex = left;
        }
        if ((right < n) && (heap[right]->val < heap[curIndex]->val)) {
            curIndex = right;
        }
        if (curIndex != p) {
            ListNode* temp = heap[p];
            heap[p] = heap[curIndex];
            heap[curIndex] = temp;
            MinHeapify(heap, n, curIndex);
        }
    }
    void BuildMinHeap(vector<ListNode*>& heap, int n) {
        for (int i = (n - 1) / 2; i >= 0; --i) {
            MinHeapify(heap, n, i);
        }
    }
    vector<ListNode*> heap;
};
