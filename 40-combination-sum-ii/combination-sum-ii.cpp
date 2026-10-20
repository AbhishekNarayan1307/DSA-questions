class Solution {
public:
    void solve(set<vector<int>>& s, vector<int>& v1, vector<int>& candidates,
               int target, int i) {
        if (target == 0) {
            s.insert(v1);
            return;
        }
        if (target < 0 || i >= candidates.size())
            return;
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;

            v1.push_back(candidates[j]);
            solve(s, v1, candidates, target - candidates[j], j + 1);
            v1.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Change 1

        vector<vector<int>> v;
        set<vector<int>> s;
        vector<int> v1;

        solve(s, v1, candidates, target, 0);

        for (auto x : s)
            v.push_back(x);

        return v;
    }
};