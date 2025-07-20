class Solution {
public:
    int rev(vector<char>& s, int i, int e){
        if(i>=e){
            return 0;
        }
        swap(s[i],s[e]);
        return rev(s, i+1, e-1);
    }
    void reverseString(vector<char>& s) {
        int e = s.size();
        rev(s, 0,e-1);
    }
};