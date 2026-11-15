class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if((j-i+1 >= l) && (j-i+1<=r) && sum > 0){
                    res = min(sum, res);
                }
            }
        }
        return res!=INT_MAX?res:-1;
    }
};