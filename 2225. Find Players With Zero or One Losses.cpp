class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> indeg;
        
        for(auto &x : matches) {
            indeg[x[1]]++;
            indeg[x[0]] = indeg[x[0]];
        }

        vector<vector<int>> ans(2);

        for(auto &x : indeg) {
            if(x.second == 0) ans[0].push_back(x.first);
            else if(x.second == 1) ans[1].push_back(x.first);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};
