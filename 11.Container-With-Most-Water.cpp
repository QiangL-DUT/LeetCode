class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            if (height[i] <= height [j]) {
                int temp = height[i] * (j - i);
                if (temp > result) {
                    result = temp;
                }
                ++i;
            }
            else {
                int temp = height[j] * (j - i);
                if (temp > result) {
                    result = temp;
                }
                --j;
            }
        }
        return result;
    }
};
