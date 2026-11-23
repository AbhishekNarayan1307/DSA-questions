class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string temp = goal + goal;
        if(temp.find(s) != string::npos){
            return true;
        }
        else return false;
    }
};