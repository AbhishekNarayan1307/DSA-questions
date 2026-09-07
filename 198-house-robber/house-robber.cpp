class Solution {
public:
    // int solve(int i, int n, unordered_map<int, int> &dp, vector<int>& nums ){
    //     if(i>=n) return 0;
    //     if(dp.find(i) != dp.end()) return dp[i];
    //     int steal = nums[i] + solve(i+2, n, dp, nums );
    //     int skip = solve(i+1, n, dp, nums);
    //     dp[i] = max(steal, skip);
    //     return dp[i];
    // }
    int rob(vector<int>& nums) {
        // unordered_map<int, int> dp;
        // return solve(0, nums.size(), dp, nums);
        int n = nums.size();
        vector<int>dp(n+2, 0);
        for(int i = n -1; i>=0; i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};