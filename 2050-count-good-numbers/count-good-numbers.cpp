class Solution {
public:
    const int MOD = 1e9+7;

    long long binaryExp(long long a, long long b){
        long long res = 1;
        while(b){
            if(b&1){
                res = (res*a)%MOD;
            }
            a = (a*a)%MOD;
            b/=2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        return (binaryExp(4,n/2) * binaryExp(5,n-n/2))%MOD;
    }
};