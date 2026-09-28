class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 2;
        int current = 2;

        if (nums.size() <= 2) {
            return nums.size();
        }

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + nums[i-2]) {
                current++;
                res = max(res, current);
            } else {
                current = 2;
            }
        }

        return res;
    }
};