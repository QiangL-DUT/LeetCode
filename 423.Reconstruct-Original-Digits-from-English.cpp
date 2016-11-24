class Solution {
public:
    string originalDigits(string s) {
        vector<int> letters(26,0);
        for (auto c: s) {
            ++letters[c - 'a']; 
        }
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> order = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<char> dis_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> counts(10, 0);
        for (int i = 0;i < 10; ++i) {
            int num = letters[dis_char[i] - 'a'];
            counts[order[i]] = num;
            for (auto c: words[i]) {
                letters[c - 'a'] -= num;
            }
        }
        string result;
        for (int i = 0; i < 10; ++i) {
            result += string(counts[i], char(i +'0'));
        }
        return result;
    }
};
