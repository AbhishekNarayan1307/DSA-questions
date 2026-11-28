class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 1) return 1;
        if(nums.size() == 2){
            if(nums[0] == nums[1]) return 2;
            else{
                return 1;
            }
        }
        if(nums[0] >= nums[1]) res++;
        if(nums[nums.size() - 1] >= nums[nums.size() - 2]) res++;
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] >= (double)(nums[i-1] + nums[i+1])/2) res++;
        }
        return res;
    }
};