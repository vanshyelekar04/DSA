class Solution {
public:
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;
        for (int left = low; left <= mid; left++) {
            while (right <= high && (long long)arr[left] > 2LL * arr[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }
        return cnt;
    }
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return 0; // no count here
    }
    int merge_sort(vector<int>& arr, int low, int high) {
        int count = 0;
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        count += merge_sort(arr, low, mid);
        count += merge_sort(arr, mid + 1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};