class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int prefixSum = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            if(prefixSum == k){
                count++;
            }
            int rem = prefixSum - k;
            if(mpp.find(rem)!=mpp.end()){
                count+=mpp[rem];
            }
            
                mpp[prefixSum]++;
        }
        return count;
    }
};