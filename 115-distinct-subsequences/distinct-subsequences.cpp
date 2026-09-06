class Solution {
public:
    long long solve(string &s, string&t, int n, int m, vector<vector<long long>> &dp, int i, int j){
        if(i==n && j!=m) return 0;
        else if(j == m) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            long long a = solve(s, t, n, m, dp, i+1, j+1);
            long long b = solve(s, t, n, m, dp, i+1, j);
            if(a > INT_MAX - b){
                dp[i][j] = INT_MAX;
            }
            else{
                dp[i][j] = solve(s, t, n, m, dp, i+1, j+1) + solve(s, t, n, m, dp, i+1, j);
            }
        }
        else{
            dp[i][j] = solve(s, t, n, m, dp, i+1, j);
        }
        return dp[i][j];

    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>>dp(n+1, vector<long long>(m+1, -1));
        return solve(s, t, n, m, dp, 0, 0);
    }
};