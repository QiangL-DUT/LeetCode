class Solution {
public:
    string reverseString(string s) {
        char temp;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};
