/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode *head) {
        ListNode *temp = head;
        int n = 0;
        while (temp != NULL) {
            temp = temp->next;
            ++n;
        }
        return sortedListToBST(head, n);
    }
private:
    TreeNode* sortedListToBST(ListNode *head, int n) {
        if (n <= 0) {
            return NULL;
        }
        ListNode *mid = head;
        int k;
        for (k = 0; k < n / 2; ++k) {
            mid = mid->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, k);
        root->right = sortedListToBST(mid->next, n - k - 1);
        return root;
    }
};
