class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int cur_max = 0;
        int sum_ = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            cur_max += i * A[i];
            sum_ += A[i];
        }
        int result = cur_max;
        for (int i = 0; i < n - 1; ++i) {
            cur_max += n * A[i] - sum_;
            result = max(result, cur_max);
        }
        return result;
    }
};
