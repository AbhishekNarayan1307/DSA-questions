
class Solution {
public:
    void solve(string digits, string mp[], vector<string>& ans, string op, int i) {
        if (i == digits.length()) {
            ans.push_back(op);
            return;
        }

        int num = digits[i] - '0';
        string val = mp[num];

        for (int j = 0; j < val.length(); j++) {
            op.push_back(val[j]);
            solve(digits, mp, ans, op, i + 1);
            op.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string mp[10] = {"", "", "abc", "def", "ghi", "jkl",
                         "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        solve(digits, mp, ans, "", 0);
        return ans;
    }
};
