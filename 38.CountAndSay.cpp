class Solution {
public:
    string countAndSay(int n) {
        string res1 = "1", res2;
        string* sp1 = &res1;
        string* sp2 = &res2;
        for (int i = 2; i <= n; ++i) {
            int count = 1;
            char c = (*sp1)[0];
            for (int j = 1; j < sp1->size(); ++j) {
                if ((*sp1)[j] == c) {
                    ++count;
                }
                else {
                    (*sp2).push_back(count + '0');
                    (*sp2).push_back(c);
                    c = (*sp1)[j];
                    count = 1;
                }
            }
            (*sp2).push_back(count + '0');
            (*sp2).push_back(c);
            (*sp1) = "";    
            string* temp = sp1;
            sp1 = sp2;
            sp2 = temp;
        }
        return *sp1;
    }
};
