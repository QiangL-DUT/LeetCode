class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len = max(len1, len2);
        string result(len, '0');
        int carry = 0;
        while (len > 0) {
            int sum = carry;
            if (len1 > 0) {
                sum += num1[--len1] - '0';
            }
            if (len2 > 0) {
                sum += num2[--len2] - '0';
            }
            result[--len] = sum % 10 + '0';
            carry = sum / 10;
        }
        return carry == 0? result: '1' + result;
    }
};
