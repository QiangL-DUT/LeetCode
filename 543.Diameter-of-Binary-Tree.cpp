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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        return dfs(root)[1];
    }
private:
    vector<int> dfs(TreeNode* root) {
        vector<int> res(2, 0);
        int lmax = 0, rmax = 0;
        if (root->left != NULL) {
            vector<int> temp = dfs(root->left);
            lmax = temp[0];
            res[1] = temp[1];
        }
        if (root->right != NULL) {
            vector<int> temp = dfs(root->right);
            rmax = temp[0];
            res[1] = max(res[1], temp[1]);
        }
        if (res[1] < lmax + rmax)
            res[1] = lmax + rmax;
        res[0] = max(lmax, rmax) + 1;
        return res;
    }
};
