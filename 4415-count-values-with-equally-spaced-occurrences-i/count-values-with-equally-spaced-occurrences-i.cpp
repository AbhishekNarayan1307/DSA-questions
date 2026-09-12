class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;
        // number vs count
        for(int a : nums){
            mp[a]++;
        }
        vector<int> special;
        for(auto&[num, cnt]:mp){
            if(cnt == 3) special.push_back(num);
        }
        int res = 0;
        for(int k : special){
            int f = INT_MAX, s = INT_MAX, t = INT_MAX;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == k){
                    if(f > j) f = j;
                    else if(s > j) s = j;
                    else t = j;
                }
                
            }
            if(t - s == s - f) res++;
        }
        return res;
    }
};