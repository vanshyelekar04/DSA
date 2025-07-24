class Solution {
public:

    void helperFunc(int index, vector<vector<int>>& ans, vector<int>& ds, vector<int>& arr, int target){
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[index]<=target){
            ds.push_back(arr[index]);
            helperFunc(index, ans, ds, arr, target - arr[index]);
            ds.pop_back();
        }
        helperFunc(index+1, ans, ds, arr, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helperFunc(0, ans, ds, candidates, target);
        return ans;
    }
};