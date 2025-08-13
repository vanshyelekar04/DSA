class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int take = dp[i - 2] + nums[i];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != n - 1) temp1.push_back(nums[i]);
            if (i != 0) temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};