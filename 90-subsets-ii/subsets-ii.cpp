class Solution {
public:
    void helper(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& current){
        ans.push_back(current);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            current.push_back(nums[i]);
            helper(i+1, nums, ans, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(), nums.end());
        helper(0, nums, ans, current);
        return ans;
    }
};