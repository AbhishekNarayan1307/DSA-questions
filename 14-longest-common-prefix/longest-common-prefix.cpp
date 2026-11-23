class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = "";
        int mn = INT_MAX;

        for (string x : strs) {
            mn = min(mn, (int)x.length());
        }

        for (int i = 0; i < mn; i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != ch) {
                    return ans;
                }
            }

            ans += ch;
        }

        return ans;
    }
};