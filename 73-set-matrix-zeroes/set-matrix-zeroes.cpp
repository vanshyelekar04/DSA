class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();

        // collect original zero positions
        vector<pair<int,int>> zeros;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) zeros.emplace_back(i, j);
            }
        }

        // for each original zero, zero its whole row and column
        for (auto &p : zeros) {
            int r = p.first, c = p.second;
            for (int j = 0; j < m; ++j) matrix[r][j] = 0;
            for (int i = 0; i < n; ++i) matrix[i][c] = 0;
        }
    }
};
