class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return "";
        }
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int len1 = num1.size();
        int len2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(len1 + len2, '0');
        for (int i = 0; i < len2; ++i) {
            mulSingle(res, i, num1, num2[i]);
        }
        if (res[len1 + len2 -1] == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
private:
    void mulSingle(string& res, int k, string& str, char c) {
        int carry = 0;
        for (int i = 0; i < str.size(); ++i) {
            int val = res[k + i] - '0' + (str[i] - '0') * (c - '0') + carry; 
            res[k + i] = val % 10 +'0';
            carry = val / 10;
        }
        if (carry) {
            res[k + str.size()] = carry + '0';
        }
    }
};
