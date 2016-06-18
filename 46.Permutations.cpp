class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& nums, int k) {
        if (k == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = k; i < nums.size(); ++i) {
            swap(nums[k],nums[i]);
            helper(res, nums, k+1);
            swap(nums[k],nums[i]);
        }
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
