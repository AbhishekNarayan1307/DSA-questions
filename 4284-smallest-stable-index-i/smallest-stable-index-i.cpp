class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            mx = *max_element(nums.begin(), nums.begin() + i + 1);
            mn = *min_element(nums.begin() + i, nums.end());
            if(abs(mx - mn) <= k) return i;
        }
        return -1;
    }
};