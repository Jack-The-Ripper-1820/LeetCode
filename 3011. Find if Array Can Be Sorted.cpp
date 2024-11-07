class Solution {
    void bubble_sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1] && __builtin_popcount(arr[j]) == __builtin_popcount(arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) break;
    }
}
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> cnums = nums;
        sort(cnums.begin(), cnums.end());
        bubble_sort(nums);
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != cnums[i]) return false;
        }

        return true;
    }
};
