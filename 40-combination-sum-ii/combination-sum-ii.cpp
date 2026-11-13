class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& v1,
               vector<int>& candidates, int target, int i) {

        if (target == 0) {
            ans.push_back(v1);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            if (candidates[j] > target)
                break;

            v1.push_back(candidates[j]);
            solve(ans, v1, candidates, target - candidates[j], j + 1);
            v1.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v1;

        solve(ans, v1, candidates, target, 0);

        return ans;
    }
};