class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int slow = 0;
        int fast = 1;
        sort(nums.begin(), nums.end());
        while(fast <= n){
            if(nums[slow] == nums[fast]) return nums[slow];
            slow++;
            fast++;
        }
        return -1;
    }
};