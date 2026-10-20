class Solution {
public:
    bool isPal(string s, int start, int end){
        while(start < end){
            if(s[start]!= s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>>&res, vector<string>&path, int start){
        if(start == s.length()){
            res.push_back(path);
            return;
        }
        for(int end = start + 1; end <= s.length(); end++){
            if(isPal(s, start, end-1)){
                path.push_back(s.substr(start, end - start));
                solve(s, res, path, end);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>path;
        solve(s, res, path, 0);
        return res; 
    }
};