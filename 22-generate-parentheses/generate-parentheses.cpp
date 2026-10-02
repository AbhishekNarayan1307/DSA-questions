class Solution {
public:
    void helper(int n, vector<string> &v, int oc, int cc, string s){
        if(oc == n && cc == n){
            v.push_back(s);
            return;
        }
        if(oc < n){
            helper(n, v, oc + 1, cc, s+"(" );
        }
        if(cc < oc){
            helper(n, v, oc, cc + 1, s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc = 0;
        int cc = 0;
        helper(n, v, oc, cc, "");
        return v;
    }
};