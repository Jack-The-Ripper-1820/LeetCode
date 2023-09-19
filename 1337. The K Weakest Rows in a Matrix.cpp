class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> cnt(mat.size());

        for(int i = 0; i < mat.size(); i++) {
            cnt[i] = {count(mat[i].begin(), mat[i].end(), 1), i};
        }

        sort(cnt.begin(), cnt.end());

        vector<int> ans(min((int)cnt.size(), k));

        for(int i = 0; i < min((int)cnt.size(), k); i++) ans[i] = cnt[i].second;

        return ans;
    }
};
