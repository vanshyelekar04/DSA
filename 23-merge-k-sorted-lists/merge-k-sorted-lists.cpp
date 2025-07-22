class Solution {
public:
    ListNode* convertarrtoLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    void merge_sort(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != nullptr) {
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }

        if (ans.empty()) return nullptr;

        merge_sort(ans, 0, ans.size() - 1);
        return convertarrtoLL(ans);
    }
};
