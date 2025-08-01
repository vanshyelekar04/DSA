class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;
        for(string &word:strs){
            int count[26] = {0};
            for(char c:word){
                count[c-'a']++;
            }
            string key;
            for(int i=0;i<26;i++){
                key += "#"+to_string(count[i]);
            }
            mpp[key].push_back(word);
        }
        vector<vector<string>> result;
        for (auto &entry : mpp) {
            result.push_back(entry.second);
        }
        return result;
    }
};