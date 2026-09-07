class Solution {
public:
    // int fn(int i, int n, unordered_map<int,int> &dp ){
    //     if(i==n) return 1;
    //     if(i>n) return 0;
    //     if(dp.find(i) != dp.end()) return dp[i];
    //     dp[i] = fn(i+1, n, dp) + fn(i+2, n, dp);
    //     return dp[i];
    // }
    int climbStairs(int n) {
        // unordered_map<int,int> dp;
        // return fn(0, n, dp);
        vector<int>dp(n+2, 0);
        dp[n] = 1;
        for(int i = n - 1 ; i >= 0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
    }
    
};