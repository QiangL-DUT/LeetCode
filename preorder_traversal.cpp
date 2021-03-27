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

// 二叉树的前序遍历
class Solution {
public:
    // 非递归版本
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while(!node_stack.empty()) {
            TreeNode* cur = node_stack.top();
            node_stack.pop();
            res.push_back(cur->val);
            if (cur->right) node_stack.push(cur->right);
            if (cur->left) node_stack.push(cur->left);
        }
        return res;
    }

    // 递归版本
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(res, root);
        return res;
    }
private:
    void preorderTraversal(vector<int>& res, TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        if (root->left) {
            preorderTraversal(res, root->left);
        }
        if (root->right) {
            preorderTraversal(res, root->right);
        }
    }
};