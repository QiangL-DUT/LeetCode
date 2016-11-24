class Solution {
public:
    int integerReplacement(int n) {
        unsigned m = n;
        int k = 0;
        while(m != 1) {
            if (m == 3) {
                k += 2;
                break;
            }
            else if ((m & 1) == 0) {
                m /= 2;
            }
            else if ((m & 3) == 3) {
                m += 1;
            }
            else {
                m -= 1;
            }
            ++k;
        }
        return k;
    }
};
