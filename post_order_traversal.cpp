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
class Solution {
public:
    // 非递归版本
    vector<int> postorderTraversal(TreeNode* root) {
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
                res.push_back(cur->val);
                stack_node.pop();
                stack_label.pop();
            } else {
                stack_label.pop();
                stack_label.push(true);
                if (cur->right) {
                    stack_node.push(cur->right);
                    stack_label.push(false);
                }
                if (cur->left) {
                    stack_node.push(cur->left);
                    stack_label.push(false);
                }
            }
        }
        return res;
    }

    // 递归版本
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder_traversal_helper(res, root);
        return res;
    }
private:
    void postorder_traversal_helper(vector<int>& res, TreeNode* root) {
        if (!root) return;
        if (root->left) {
            postorder_traversal_helper(res, root->left);
        }
        if (root->right) {
            postorder_traversal_helper(res, root->right);
        }
        res.push_back(root->val);
    }
};