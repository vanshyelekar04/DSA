class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            long long val = 1LL * mid * mid;
            if(val == x){
                return mid;
            }
            else if(val<x){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};