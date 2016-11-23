class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        int min_val = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            min_val = min(min_val, nums[i]);
            result += nums[i];
        }
        result -= n * min_val;
        return result;
    }
};
