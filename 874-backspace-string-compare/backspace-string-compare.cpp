class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sans;
        string tans;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#' && !sans.empty()) sans.pop_back();
            else if(s[i] == '#') continue;
            else sans.push_back(s[i]);
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#' && !tans.empty()) tans.pop_back();
            else if(t[i] == '#') continue;
            else tans.push_back(t[i]);
        }
        if(sans == tans) return true;
        return false;
    }
};