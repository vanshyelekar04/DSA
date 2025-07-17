class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int prev2 = 0;
        int prev = 1;
        for (int i = 2; i <= n; i++) {
            int cur1 = prev2 + prev;
            prev2 = prev;
            prev = cur1;
        }
        return prev;
    }
};