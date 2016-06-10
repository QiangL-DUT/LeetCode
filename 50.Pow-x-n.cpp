class Solution {
public:
    double myPow(double x, int n) {
        if (!x) {
            return 0;
        }
        else if (n < 0) {
            return 1.0 / helper(x, -n);
        }
        else {
            return helper(x, n);
        }
    }
private:
    double helper(double x, int n) {
        if (!n) {
            return 1;
        }
        double temp = helper(x, n / 2);
        if (n % 2) {
            return x * temp * temp;
        }
        else {
            return temp * temp;
        }
    }
};
