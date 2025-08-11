class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    int moveup = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int moveleft = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = grid[i][j]+min(moveup, moveleft);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};