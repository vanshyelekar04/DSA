class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1, ans1=-1, ans2=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                ans1 = mid;
                e=mid-1;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        if(ans1 == -1) return {-1, -1};
        s = 0;
        e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                ans2 = mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return {ans1, ans2};
    }
};