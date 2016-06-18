class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(res, nums, 0);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& nums, int k) {
        if (k == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        helper(res, nums, k+1);
        for (int i = k + 1; i < nums.size(); ++i) {
            int j;
            for (j = k; j <i; ++j) {
                if (nums[i] == nums[j]) 
                    break;
            }
            if (j == i) {
                swap(nums[k],nums[i]);
                helper(res, nums, k+1);
                swap(nums[k],nums[i]);
            }
        }
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
