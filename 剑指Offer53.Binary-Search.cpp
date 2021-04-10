class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] > target) {
                j = mid - 1;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        if (j < 0 || nums[j] != target) return 0;
        int left_index = j;
        i = 0;
        j = n - 1;
        while (i < j) {
            int mid = (i + j + 1) / 2;
            if (nums[mid] > target) {
                j = mid - 1;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                i = mid;
            }
        }
        int right_index = i;
        return right_index - left_index + 1;
    }
};