class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int prev = 1, prev2 = 1;
        for(int i=2;i<=n;i++){
            int temp = prev2;
            prev2 = prev+prev2;
            prev = temp;
        }
        return prev2;
    }
};