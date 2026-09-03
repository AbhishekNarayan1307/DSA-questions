class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        if(a < 1) return 0;
        vector<int> dp(a + 1);
        for(int i = 1; i <= a; i++){
            dp[i] = INT_MAX;
            for(int c : coins){
                if(c <= i && dp[i - c] != INT_MAX){
                    dp[i] = min(dp[i], dp[i- c] + 1);
                }
            }
        }
        if(dp[a] == INT_MAX) return -1;
        return dp[a];
    }
};