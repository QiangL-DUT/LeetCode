class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sortNums = nums;
        vector<int> result;
        sort(sortNums.begin(), sortNums.end());
        int index1 = 0, index2 = nums.size() - 1;
        while (index1 < index2) {
            int temp = sortNums[index1] + sortNums[index2];
            if ( temp == target) {
                break;
            }
            else if ( temp > target) {
                --index2;
            }
            else {
                ++index1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == sortNums[index1])
                result.push_back(i);
            else if (nums[i] == sortNums[index2])
                result.push_back(i);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
