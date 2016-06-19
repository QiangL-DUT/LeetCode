class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < (m + 1 ) / 2; ++j) {
                int iCur = i, jCur = j;
                int iPre = 2 * (double(m -1) / 2) -j, jPre = i;
                int val = matrix[i][j];
                for (int k = 0; k < 3; ++k) {
                    matrix[iCur][jCur] = matrix[iPre][jPre];
                    iCur = iPre;
                    jCur = jPre;
                    iPre = 2 * (double(m -1) / 2) -jCur;
                    jPre = iCur;
                }
                matrix[iCur][jCur] = val;
            }
        }
    }
};
