class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        if (target < candidates[index]) {
            return;
        }
        path.push_back(candidates[index]);
        helper(res, candidates, target - candidates[index], path, index + 1);
        path.pop_back();
        while ((index < candidates.size() - 1) && (candidates[index] == candidates[index + 1])) {
            ++index;
        }
        helper(res, candidates, target, path, index + 1);
    }
};
