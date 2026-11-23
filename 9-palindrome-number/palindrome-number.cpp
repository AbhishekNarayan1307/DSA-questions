class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x);
        for(int i = 0; i < y.length()/2; i++){
            if(y[i] != y[y.length()-1-i]) return false;
        }
        return true;
    }
};