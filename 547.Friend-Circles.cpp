// BFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        vector<bool> visited(M.size(), false);
        for (int i = 0; i < M.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                count++;
                helper(M, visited, i);
            }
        }
        return count;
    }
private:
    void helper(vector<vector<int>>& M, vector<bool>& visited, int cur) {
        for (int i = 0; i < M.size(); i++) {
            if ((M[cur][i] == 1) && (visited[i] == false)) {
                visited[i] = true;
                helper(M, visited, i);
            }
        }
    }
};
