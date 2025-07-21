class Solution {
public:
    void sub(int idx, int n, vector<int>& nums, vector<int>& current,
             vector<vector<int>>& result) {
        if (idx >= n) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[idx]);
        sub(idx + 1, n, nums, current, result);
        current.pop_back();
        sub(idx + 1, n, nums, current, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sub(0, nums.size(), nums, current, result);
        return result;
    }
};