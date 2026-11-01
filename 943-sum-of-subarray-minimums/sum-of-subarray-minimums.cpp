class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        stack<pair<int,int>> st;
        vector<int> left(n), right(n);

        // Previous smaller or equal element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top().second;
            st.push({arr[i], i});
        }

        while (!st.empty()) st.pop();

        // Next strictly smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first > arr[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top().second - i;
            st.push({arr[i], i});
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + 1LL * arr[i] * left[i] * right[i]) % mod;
        }

        return ans;
    }
};