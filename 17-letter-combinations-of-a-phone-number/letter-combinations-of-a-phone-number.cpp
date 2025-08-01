class Solution {
public:
    void helper(int index, vector<string>& mapping, string digits, string current, vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        string letters = mapping[digits[index]-'0'];
        for(auto it:letters){
            current.push_back(it);
            helper(index+1, mapping, digits, current, ans);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string current;
        vector<string> mapping = {
            "",    "",    "abc", "def", "ghi",
            "jkl", "mno", "pqrs","tuv","wxyz"
        };
        vector<string> ans;
        helper(0, mapping, digits, current, ans);
        return ans;
    }
};