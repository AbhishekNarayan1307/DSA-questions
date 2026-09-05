class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx;
        vector<int> mn;
        int mxx = INT_MIN;
        int mnn = INT_MAX;
        for(int i = 0; i < n; i++){
            mxx = max(mxx, nums[i]);
            mx.push_back(mxx);
        }
        int x = n - 1;
        for(int i = n - 1; i>=0; i--){
            mnn = min(mnn, nums[i]);
            mn.push_back(mnn);
        }
        reverse(mn.begin(), mn.end());
        for(int i = 0; i < n; i++){
            if((mx[i] - mn[i]) <= k) return i;
        }
        return -1;
    }
};