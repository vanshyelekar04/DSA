class Solution {
public:
    int rev(vector<char>& s, int i, int e){
        if(i>=e/2){
            return 0;
        }
        swap(s[i],s[e-i-1]);
        return rev(s, i+1,e);
    }
    void reverseString(vector<char>& s) {
        int e = s.size();
        rev(s, 0, e);
    }
};