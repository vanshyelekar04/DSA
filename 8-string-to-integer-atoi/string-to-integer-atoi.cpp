class Solution {
public:
    int helper(const string& s, int i, int sign, int result) {
        // base case
        if (i >= s.size() || !isdigit((unsigned char)s[i])) {
            return result * sign;
        }
        int digit = s[i] - '0';
        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        return helper(s, i + 1, sign, result * 10 + digit);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        // remove whitespaces
        while (i < s.size() && isspace((unsigned char)s[i])) {
            i++;
        }
        // check sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        return helper(s, i, sign, 0);
    }
};