class Solution {
public:
    const int MOD = 1e9+7;
    long long helper(long long x, long long n){
        if(n==0) return 1;
        if(n==1) return x%MOD;

        long long half = helper(x,n/2);
        long long res = (half*half)%MOD;
        if(n%2 == 1){
            res = (res*x)%MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long oddCount = n/2;
        long long even = helper(5,evenCount);
        long long odd = helper(4,oddCount);
        return (even*odd)%MOD;
    }
};