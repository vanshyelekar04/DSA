class Solution {
public:
    int reverse(int x) {
        long long number = 0;
        while(x!=0){
            int ld = x%10;
            number = (number*10)+ld;
            x = x/10;
        }
        if (number < INT_MIN || number > INT_MAX) {
            return 0;
        }
        return (int)number;
    }
};