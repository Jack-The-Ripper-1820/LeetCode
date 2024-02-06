class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> mp;
        
        for(string &x : strs) {
            array<int, 26> freq = {0};
            
            for(char y : x) freq[y - 'a']++;
            
            mp[freq].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto &x : mp) ans.push_back(x.second);
        
        return ans;
    }
};
