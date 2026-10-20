class Solution {
private:
    void solve(vector<vector<int>> &ans, vector<int> &op, int i, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(op);
            return;
        }
        solve(ans, op, i+1, nums);
        op.push_back(nums[i]);
        solve(ans, op, i+1, nums);
        op.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(ans, op, 0, nums);
        return ans;
    }
};