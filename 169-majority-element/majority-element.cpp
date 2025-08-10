class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0, count = 0;
        for(auto it:nums){
            if(count == 0){
                candidate = it;
            }
            count += (it ==  candidate) ? 1:-1;
        }
        return candidate;    
    }
};