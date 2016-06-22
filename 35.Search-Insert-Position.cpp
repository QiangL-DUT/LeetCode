class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0]) {
            return 0;
        }
        if (target > nums[nums.size() - 1]) {
            return nums.size();
        }
        if (target == nums[nums.size() - 1]) {
            return nums.size() - 1;
        }
        int index1 = 0;
        int index2 = nums.size() - 1;
        while (index1 < index2 - 1) {
            int mid = (index1 + index2) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                index1 = mid;
            }
            else {
                index2 = mid;
            }
        }
        return index1 + 1;
    }
};
