class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        helper(res, candidates, target, path, 0);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& path, int index) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (candidates.size() == index) {
            return;
        }
        while ((index < candidates.size() - 1) && (candidates[index] == candidates[index + 1])) {
            ++index;
        }
        for (int i = 0;  i <= target; i += candidates[index]) {
            helper(res, candidates, target - i, path, index + 1);
            path.push_back(candidates[index]);
        }
        for (int i = 0; i <= target; i += candidates[index]) {
            path.pop_back();
        }
    }
};
