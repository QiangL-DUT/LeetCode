class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> label(255, false);
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            unsigned index = unsigned(s[i]);
            if (label[index]) {
                int len = i - start;
                if (len > maxLen) {
                    maxLen = len;
                }
                while (s[start] != s[i]) {
                    index = unsigned(s[start]);
                    label[index] = false;
                    ++start;
                }
                ++start;
            }
            else {
                label[index] = true;
            }
        }
        if (s.size() - start > maxLen) {
            maxLen = s.size() - start;
        }
        return maxLen;
    }
};
