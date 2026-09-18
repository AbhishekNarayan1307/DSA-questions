class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26, -1);
        vector<int> end(26);
        vector<bool> isVal(26, true);
        vector<string> result;
        for(int i = 0; i < s.length(); i++){
            int idx = s[i] - 'a';
            if(start[idx] == -1){
                start[idx] = i;
            }
            end[idx] = i;
        }
        for(int c = 0; c < 26; c++){
            if(start[c] == -1) continue;
            for(int i = start[c]; i <= end[c]; i++){
                if(start[s[i] - 'a'] < start[c]){
                    isVal[c] = false;
                    break;
                }
                end[c] = max(end[c], end[s[i] - 'a']);
            }
        }
        int lastIdxSt = INT_MAX;
        for(int i = s.length() - 1; i >= 0; i--){
            int c = s[i] - 'a';
            if(!isVal[c]) continue;
            if(i == start[c] && end[c] < lastIdxSt){
                result.push_back(s.substr(i, end[c] - i + 1));
                lastIdxSt = i;
            }
        }return result;
    }
};