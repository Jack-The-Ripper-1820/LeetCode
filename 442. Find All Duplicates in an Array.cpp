class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int ind = abs(nums[i]) - 1;
            
            nums[ind] = -nums[ind];

            if(nums[ind] > 0) ans.push_back(ind + 1);
        }
        
        return ans;
    }
};
