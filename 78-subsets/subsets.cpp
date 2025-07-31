class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& ans, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[index]);
        helper(index + 1, nums, ans, result);
        ans.pop_back();
        helper(index + 1, nums, ans, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        helper(0, nums, ans, result);
        return result;
    }
};