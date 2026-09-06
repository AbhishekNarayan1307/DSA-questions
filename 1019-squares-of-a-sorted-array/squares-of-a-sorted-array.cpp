class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int dig = nums[i];
            nums[i] = dig*dig;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};