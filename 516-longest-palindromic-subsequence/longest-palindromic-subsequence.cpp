class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n1 = s.length();
        int n2 = s.length();
        string sr = s;
        reverse(sr.begin(), sr.end());
        vector<vector<int>> dp(n1 + 1, vector<int>(n2+1, 0));
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s[i-1] == sr[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }return dp[n1][n2];     
    }
};