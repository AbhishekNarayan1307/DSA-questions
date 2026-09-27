class Solution {
public:
    int y = 0;
    int solve(int x, vector<vector<int>> &dp, int i){
        if(x==0) return 0;
        if(x<0) return INT_MAX/2;
        if(i>y) return INT_MAX/2;
        if(dp[x][i] != -1) return dp[x][i];
        int take = 1 + solve(x - i*i, dp, i);
        int skip = solve(x, dp, i+1);
        return dp[x][i] = min(take, skip);
    }
    int numSquares(int n) {
        for(int j = 1; j*j <= n; j++){
            y++;
        }
        vector<vector<int>> dp(n+1, vector<int>(y+1, -1));
        return solve(n, dp, 1);
         
    }
};