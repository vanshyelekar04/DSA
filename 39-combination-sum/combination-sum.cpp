class Solution {
public:
    void helper(int index, int target, vector<int>& arr, vector<int>& current,
                vector<vector<int>>& result) {
        if (index == arr.size()) {
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }
        if (arr[index] <= target) {
            current.push_back(arr[index]);
            helper(index, target - arr[index], arr, current, result);
            current.pop_back();
        }
        helper(index + 1, target, arr, current, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        helper(0, target, candidates, current, result);
        return result;
    }
};