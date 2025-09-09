class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int prev = 1;
        int prev2 = 1;
        int cur = 0;
        for(int i=2;i<=n;i++){
            cur = prev2+prev;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};