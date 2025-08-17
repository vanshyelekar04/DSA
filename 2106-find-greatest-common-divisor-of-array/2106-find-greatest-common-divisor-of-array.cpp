class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sm = *min_element(nums.begin(), nums.end());
        int lg = *max_element(nums.begin(), nums.end());
        while(lg%sm!=0){
            int temp = lg%sm;
            lg = sm;
            sm = temp;
        }
        return sm;
    }
};