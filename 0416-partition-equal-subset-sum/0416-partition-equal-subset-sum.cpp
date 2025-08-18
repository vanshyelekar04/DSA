class Solution {
public:
    bool helper(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0){
            return nums[0]==target;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        bool notpick = helper(index-1, target, nums, dp);
        bool pick = false;
        if(nums[index]<=target){
            pick = helper(index-1, target-nums[index], nums, dp);
        }
        return dp[index][target]=(pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums){
            sum += it;
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>>dp (n+1, vector<int>(target+1, -1));
        return helper(n-1, target, nums, dp);
    }
};