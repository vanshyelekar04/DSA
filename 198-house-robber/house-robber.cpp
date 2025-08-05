class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp){
        if (i<0) return 0;
        dp[0] = nums[0];
        int neg = 0;
        for(int i = 1; i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2]; //negative issue solved
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n+1, -1);
        return helper(n-1, nums, dp);
    }
};