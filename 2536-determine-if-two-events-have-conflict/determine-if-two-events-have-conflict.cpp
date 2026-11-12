class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string cs = event1[0];
        string ce = event1[1];
        string ns = event2[0];
        string ne = event2[1];
        if(cs > ne) return false;
        else if(ce < ns) return false;
        else return true;
    }
};