class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>>dp(n + 1, vector<long long>(m+1,-1));
        for(int x = 0; x<=n;x++) dp[x][0] = 1;
        for(int x = 1; x<=m;x++) dp[0][x] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    if (dp[i-1][j] > INT_MAX - dp[i-1][j-1])
                        dp[i][j] = INT_MAX;
                    else
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];

    }
};