class Solution {
public:
    int helper(const string& s, int i, int sign, int result) {
        if (i >= s.size() || !isdigit((unsigned char)s[i])) {
            return result * sign;
        }
        // converting into int
        int digit = s[i] - '0';
        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        return helper(s, i + 1, sign, result * 10 + digit);
    }

    int myAtoi(string s) {
        int i = 0;
        // removing whitespaces
        while (i < s.size() && isspace((unsigned char)s[i])) {
            i++;
        }

        int sign = 1;
        // set the sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        return helper(s, i, sign, 0);
    }
};