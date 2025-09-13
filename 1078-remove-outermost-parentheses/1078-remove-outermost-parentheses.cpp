class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter = 0;
        string ans = "";
        for(auto it:s){
            if(it == '('){
                if(counter>0) ans+=it;
                counter++;
            }
            else{
                counter--;
                if(counter>0) ans+=it;
            }
        }
        return ans;
    }
};