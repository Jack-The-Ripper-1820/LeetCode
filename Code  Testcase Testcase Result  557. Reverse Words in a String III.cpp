class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans, token;

        while(getline(ss, token, ' ')) {
            reverse(token.begin(), token.end());
            ans += token + ' ';
        }

        ans.pop_back();
        
        return ans;
    }
};
