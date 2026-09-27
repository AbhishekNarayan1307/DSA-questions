class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.length() + 1, 0);
        for(int i = 1; i < s.length(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    longest[i] = (i-2)>=0? longest[i-2] + 2: 2;
                    curMax = max(curMax, longest[i]);
                }
                else{
                    if(i- longest[i-1] - 1 >= 0 && s[i- longest[i-1] - 1] == '('){
                        longest[i] = longest[i-1] + 2 + ((i- longest[i-1] -2 >= 0)? longest[i - longest[i-1]-2]: 0);
                        curMax = max(curMax, longest[i]);
                    }
                }
            }
            
        }return curMax;
    }
};