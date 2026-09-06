class Solution {
public:
    void rotate(string &s, int k){
        char first = s[0];
        for(int j = 0; j < s.length()-1; j++){
            s[j] = s[j+1];
        }
        s[s.length()-1] = first;
        
    }
    int countRotations(string s, int k) {
        int ans = 0;
        int x = s.length();
        while(x--){
            int score = 0;
            for(int i = 0; i < s.length() - 1; i++){
                if(s[i] == s[i+1]){
                    score++;
                }        
            }if(score == k) ans++;
            rotate(s, k);
        } return ans;
    }
};