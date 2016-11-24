class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int pre = 0;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i] + A[i - 2] == 2 * A[i - 1]) {
                pre += 1;
                ans += pre;
            }
            else {
                pre = 0;
            }
        }
        return ans;
    }
};
