class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(256);
        for(char x : s){
            freq[x]++;
        }
        int ans = 0;
        for(char x = 'a'; x <= 'm'; x++){
            char mr = 'z' - (x - 'a');
            ans += abs(freq[x] - freq[mr]);
        }
        for(char x = '0'; x<= '4'; x++){
            char mr = '9' - (x - '0');
            ans += abs(freq[x] - freq[mr]);
        }
        return ans;
    }
};