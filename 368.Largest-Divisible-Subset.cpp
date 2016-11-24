class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> cur(n, 1);
        vector<int> index(n, 0);
        int max_ = 1;
        int pre = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if ((nums[i] % nums[j] == 0) && (cur[i] < cur[j] + 1)){
                    cur[i] = cur[j] + 1;
                    index[i] = j;  
                }
            }
            if (cur[i] > max_) {
                max_ = cur[i];
                pre = i;
            }
        }
        vector<int> result(max_, 0);
        for (int i = max_ - 1; i >= 0; --i) {
            result[i] = nums[pre];
            pre = index[pre];
        }
        return result;
    }
};
