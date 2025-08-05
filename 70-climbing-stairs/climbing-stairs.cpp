class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = helper(n-1,dp)+helper(n-2,dp);
    }
    int climbStairs(int n) {
        //recursive ->
        // if(n == 0) return 1;
        // if(n == 1) return 1;
        // //jump 1 or jump 2
        // return climbStairs(n-1) + climbStairs(n-2);

        //convert to memoization ->
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};