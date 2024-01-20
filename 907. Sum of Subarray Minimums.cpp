class Solution {
    static const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int ans = 0;
        
        for(int i = 0; i <= arr.size(); i++) {
            while(!st.empty() and (i == arr.size() || arr[st.top()] > arr[i])) {
                int mid = st.top(), right = i;
                st.pop();
                int left = st.empty() ? -1 : st.top();

                long lenCnt = (right - mid) * (mid - left);
                ans = (ans + (arr[mid] * lenCnt) % MOD) % MOD;
            }
            
            st.push(i);
        }
        
        return ans;
    }
};
