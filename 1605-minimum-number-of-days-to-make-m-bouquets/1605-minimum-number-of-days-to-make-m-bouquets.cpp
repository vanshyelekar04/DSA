class Solution {
public:
    int bloom(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int noofBook = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                noofBook += (count / k);
                count = 0;
            }
        }
        noofBook += (count / k);
        return noofBook >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (bloom(bloomDay, mid, m, k)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};