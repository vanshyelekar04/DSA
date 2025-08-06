class Solution {
public:
    int helper(vector<int>& nums){
        int n = nums.size();
        if (n == 0) return 0;
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += prev2; //negative issue solved
            int notpick = prev;
            int curi = max(pick, notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};