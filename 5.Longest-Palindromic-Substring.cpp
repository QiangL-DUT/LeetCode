// O(n^2) time and O(1) space
class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        if (s.empty())
            return result;
        int start = 0;
        int maxLen = 1;
        for (int mid = 0; mid < s.size(); ++mid) {
            int len;
            bool find=false;
            int index1, index2;
            for (index1 = mid -1, index2 = mid + 1; (index1 >= 0) && (index2 <= s.size() - 1); --index1, ++index2) {
                if (s[index1] != s[index2]) {
                    if (index2 - index1 -1 > maxLen) {
                        maxLen = index2 - index1 - 1;
                        start = index1 + 1;
                    }
                    break;
                    find = false;
                }
                find = true;
            }
            if ((find) && (index2 - index1 -1 > maxLen)) {
                maxLen = index2 - index1 - 1;
                start = index1 + 1;
                find = false;
            }
            for (index1 = mid, index2 = mid + 1; (index1 >= 0) && (index2 <= s.size() - 1); --index1, ++index2) {
                if (s[index1] != s[index2]) {
                    if (index2 - index1 - 1 > maxLen) {
                        maxLen = index2 - index1 -1;
                        start = index1 + 1;
                    }
                    break;
                    find = false;
                }
                find = true;
            }
            if ((find) && (index2 - index1 -1> maxLen)) {
                maxLen = index2 -index1 -1;
                start = index1 + 1;
                find = false;
            }
        }
        result.assign(s, start, maxLen);
        return result;
    }
};
