class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string ans(n, '0');
        int cnt = 0;
        
        for(char x : s) {
            cnt += x == '1';
        }
        
        ans[n - 1] = '1';
        cnt--;
        
        for(int i = 0; i < n - 1 && cnt; i++) {
            ans[i] = '1';
            cnt--;
        }
        
        return ans;
    }
};
