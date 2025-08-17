class Solution {
public:
    bool isPalindrome(int x) {
        int duplicate = x;
        long long revNum = 0;
        while(x>0){
            int lastDigit = x%10;
            revNum = (revNum*10) + lastDigit;
            x = x/10;
        }
        return duplicate == revNum;
    }
};