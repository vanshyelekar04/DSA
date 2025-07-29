class Solution {
public:
    void helper(int index, vector<int>& nums, vector<vector<int>> &ans, vector<int> &current){
        if(index == nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        helper(index+1, nums, ans, current);
        current.pop_back();
        helper(index+1, nums, ans, current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        helper(0, nums, ans, current);
        return ans;
    }
};