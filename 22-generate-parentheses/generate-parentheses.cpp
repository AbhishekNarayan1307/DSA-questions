class Solution {
public:
    void solve(vector<string> &ans, int oc, int cc, string s, int n){
        if(oc == n && cc == n){
            ans.push_back(s);
            return;
        }
        if(oc < n){
            solve(ans, oc + 1, cc, s + "(", n);
        }
        if(cc < oc){
            solve(ans, oc, cc+1, s + ")", n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0;
        int cc = 0;
        solve(ans, oc, cc, "",n);
        return ans;
    }
};