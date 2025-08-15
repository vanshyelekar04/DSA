class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int upLeft = matrix[i][j];
                if (j > 0)
                    upLeft += dp[i - 1][j - 1];
                else
                    upLeft += 1e9;

                int upRight = matrix[i][j];
                if (j < m - 1)
                    upRight += dp[i - 1][j + 1];
                else
                    upRight += 1e9;

                dp[i][j] = min(up, min(upLeft, upRight));
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};
