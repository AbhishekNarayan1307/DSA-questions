class Solution {
public:
    bool solve(int i, int j, string &s){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]) 
            return solve(i+1, j-1, s);
        return false;
    }
    string longestPalindrome(string s) {
        int maxLen = 0;
        int sp = 0;
        for(int i = 0; i< s.length(); i++){
            for(int j = i; j < s.length(); j++){
                if(solve(i, j, s)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }return s.substr(sp, maxLen);
    }
};