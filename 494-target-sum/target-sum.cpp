class Solution {
public:
    int solve(vector<int>& nums, int sm, vector<vector<int>>& dp, int i) {
        if(i == nums.size()) {
            return sm == 0;
        }

        if(dp[i][sm] != -1)
            return dp[i][sm];

        int c1 = 0;

        if(sm >= nums[i])
            c1 = solve(nums, sm - nums[i], dp, i + 1);

        int c2 = solve(nums, sm, dp, i + 1);

        return dp[i][sm] = c1 + c2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > total || (total + target) % 2 != 0)
            return 0;

        int sm = (total + target) / 2;

        vector<vector<int>> dp(
            nums.size() + 1,
            vector<int>(sm + 1, -1)
        );

        return solve(nums, sm, dp, 0);
    }
};