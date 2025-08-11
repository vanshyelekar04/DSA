class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
                    continue;
                if (i == 0 && j == 0)
                    dp[0][0] = 1;
                else {
                    int moveup = (i > 0) ? dp[i - 1][j] : 0;
                    int moveleft = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = moveup + moveleft;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};