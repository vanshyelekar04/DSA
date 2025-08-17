class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sm = *min_element(nums.begin(), nums.end());
        int lg = *max_element(nums.begin(), nums.end());
        for(int i=sm;i>=1;i--){
            if(sm%i==0 && lg%i==0){
                return i;
           }
        }
        return 1;
    }
};