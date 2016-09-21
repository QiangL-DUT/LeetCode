// time: O(32n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int bits_num = 8 * sizeof(int);
        for (int i = 0; i < bits_num; ++i) {
            int count = 0;
            int mask = 1 << i;
            for (int j = 0; j < n; ++j) {
                if (mask & nums[j]) {
                    ++count;
                }
            }
            if (count % 3) {
                result |= mask;
            }
        }
        return result;
    }
};
