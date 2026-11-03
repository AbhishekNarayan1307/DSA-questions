class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int mid = n/2;
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            ans += abs(nums[i] - nums[mid]);
            ans += abs(nums[n-1-i] - nums[mid]);
        }
        return ans;
    }
};