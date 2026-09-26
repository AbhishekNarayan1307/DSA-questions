class Solution {
public:
    int fn(vector<int>&a, int n, int i, int k, vector<vector<int>>&dp){
        if(i==n || k==0) return dp[i][k] = 0; 
        if(dp[i][k] != -1 ) return dp[i][k];
        if(k==2){
            int c1 = fn(a, n, i+1, k-1, dp) - a[i];
            int c2 = fn(a, n, i+1, k, dp);
            return dp[i][k] = max(c1, c2);
        }
        if(k==1){
            int c1 = fn(a, n, i+1, k-1, dp) + a[i];
            int c2 = fn(a, n, i+1, k, dp);
            return dp[i][k] = max(c1, c2);
        }
        return dp[i][k];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return fn(prices, n, 0, 2, dp);
    }
};