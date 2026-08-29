class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int nd = target - nums[i];
            if(mp.count(nd)){
                return {mp[nd], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};