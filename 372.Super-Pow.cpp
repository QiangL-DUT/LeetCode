class Solution {
public:
    const int base =1337;
    int superPow(int a, vector<int>& b) {
        int res = 1;
        int n = b.size();
        a = a % base;
        for (int i = 0; i < n; ++i) {
            res = (helper(res, 10) * helper(a, b[i])) % base;
        }
        return res;
    }
private:
    int helper(int a, int k) {         //a^k mod 1337 where 0 <= k <= 10
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res = (res * a) % base;
        }
        return res;
    }
};
