class Solution {
public:
    int solve(vector<int>& cost, int i, int res, vector<int>&dp){
        int n = cost.size();
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = cost[i] + min(solve(cost, i+1, res, dp) ,solve(cost, i+2, res, dp));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int res = 0;
        vector<int>dp(cost.size() + 1, -1);
        return min(solve(cost, 0, res, dp), solve(cost, 1, res, dp));
    }
};