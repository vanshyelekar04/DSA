class Solution {
public:
    void helper(int n, int open, int close, string path, vector<string>& result){
        if(open == close && close == n){
            result.push_back(path);
            return;
        }
        if(open<n){
            helper(n, open+1, close, path+"(", result);
        }
        if(close<open){
            helper(n, open, close+1, path+")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(n,0,0,"",result);
        return result;
    }
};