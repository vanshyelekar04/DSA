class Solution {
public:
    void helperFun(int index, vector<vector<int>>& ans, vector<int>& nums, vector<int>& arr){
        ans.push_back(arr);
        for(int i = index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            arr.push_back(nums[i]);
            helperFun(i+1, ans, nums, arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        helperFun(0, ans, nums, arr);
        return ans;
    }
};