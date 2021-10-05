class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        
        for i in range(len(nums)):
            if target - nums[i] in mp.keys():
                return [mp[target - nums[i]], i]
            mp[nums[i]] = i
        
        return []
            
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            
            if(it != mp.end())
                return {i, it->second};
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
