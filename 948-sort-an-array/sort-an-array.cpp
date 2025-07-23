class Solution {
public:
    int helperFun(vector<int>& arr, int low, int high) {
        int randomIdx = low + rand() % (high - low + 1);
        swap(arr[low], arr[randomIdx]);
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i <= j) {
            while (i <= high && arr[i] <= pivot) i++;
            while (j >= low && arr[j] > pivot) j--;

            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[j]);
        return j;
    }

    void qs(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pIndex = helperFun(arr, low, high);
            qs(arr, low, pIndex - 1);
            qs(arr, pIndex + 1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};