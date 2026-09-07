class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 1);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(nums[j]>nums[i]){
                    dp[j] = max(dp[j],1 + dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};