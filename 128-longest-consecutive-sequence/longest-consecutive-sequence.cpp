class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 1;
        int k = 1;
        if(nums.size() < 1) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == 1){
                k+=1;
            }
            else if(nums[i] == nums[i-1]) continue;
            else{
                k = 1;
            }
            res = max(res, k);
        }
        return res;
    }
};