class Solution {
public:
    int findNthDigit(int n) {
        int k = 0;
        while (true) {
            int res = n - 9 * pow(10, k) * (k + 1);
            ++k;
            if (res <= 0) {
                break;
            }
            n = res;
        }
        int quotient = (n - 1) / k;
        int remainder = (n - 1) % k;
        int nth = (quotient + pow(10, k - 1)) / pow(10, k - remainder - 1);
        return nth % 10;
    }
};
