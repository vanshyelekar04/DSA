class Solution {
public:
    long long totalhrs(vector<int>& piles, int hourly){
        long long totalhrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhrs += ((long long)piles[i] + hourly - 1) / hourly; 
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = e; 

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long total = totalhrs(piles, mid);

            if (total <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
