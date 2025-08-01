class Solution {
public:
    double helper(double x, int n){
        if(n==0) return 1.0;
        if(n==1) return x;
        double half = helper(x,n/2);
        if(n%2==0){
            return half*half;
        }else{
            return half*half*x;
        }
        return x;
    }

    double myPow(double x, int n) {
        long N = n;
        if(N<0){
            return 1.0/helper(x,-N);
        }
        return helper(x, N);
    }
};