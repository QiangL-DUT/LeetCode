class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> mapAna;
        int k = 0;
        unordered_map<string, int>::iterator iter;
        for (int i = 0; i < strs.size(); ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            iter = mapAna.find(temp);
            if (iter != mapAna.end()) {
                int index = iter->second;
                result[index].push_back(strs[i]);
            }
            else {
                mapAna[temp] = k++;
                vector<string> str(1,strs[i]);
                result.push_back(str);
            }
        }
        return result;
    }
};
