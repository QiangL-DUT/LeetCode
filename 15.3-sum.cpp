class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        triplet.resize(3);
        if (nums.size()<3)
            return result;
        sort(nums.begin(), nums.end());
        int index1 = 0, index2, index3;
        while ((index1 < nums.size() - 2) && (nums[index1] <= 0)) {
            if ((index1 > 0) && (nums[index1] == nums[index1-1])) {
                ++index1;
                continue;
            }
            index2 = index1 + 1;
            index3 = nums.size() - 1;
            while (index2 < index3) {
                int temp = nums[index2] + nums[index3];
                if ( temp == - nums[index1]) {
                    triplet[0] = nums[index1];
                    triplet[1] = nums[index2];
                    triplet[2] = nums[index3];
                    result.push_back(triplet);
                    ++index2;--index3;
                    while ((index2 < index3) && (nums[index2] == nums[index2-1])) {
                        ++index2;
                    }
                    while ((index2 < index3) && (nums[index3] == nums[index3+1])) {
                        --index3;
                    }
                }
                else if ( temp > - nums[index1]) {
                    --index3;
                }
                else {
                    ++index2;
                }
            }
            ++index1;
        }
        return result;
    }
private:
    vector<int> triplet;
};
