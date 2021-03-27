/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 二叉树的中序遍历
class Solution {
public:
    // 非递归版本
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack_node;
        stack<bool> stack_label;
        if (root) {
            stack_node.push(root);
            stack_label.push(false);
        }
        while (!stack_node.empty()) {
            TreeNode* cur = stack_node.top();
            bool flag = stack_label.top();
            if (flag) {
                stack_label.pop();
                stack_node.pop();
                res.push_back(cur->val);
                if (cur->right) {
                    stack_node.push(cur->right);
                    stack_label.push(false);
                }
            } else {
                stack_label.pop();
                stack_label.push(true);
                if (cur->left) {
                    stack_node.push(cur->left);
                    stack_label.push(false);
                }
            }
        }
        return res;
    }

    // 递归版本
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(res, root);
        return res;
    }
private:
    void inorderTraversal(vector<int>& res, TreeNode* root) {
        if (!root) return;
        if (root->left) {
            inorderTraversal(res, root->left);
        }
        res.push_back(root->val);
        if (root->right) {
            inorderTraversal(res, root->right);
        }
    }
};