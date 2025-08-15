class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s=1, e = n-2;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid-1] != nums[mid] && nums[mid+1]!=nums[mid]){
                return nums[mid];
            }
            if((mid%2 == 1) && (nums[mid-1]==nums[mid]) || (mid%2==0)&&(nums[mid+1]==nums[mid])){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
};