class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, ss;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == '*') {
                ss.push(i);
            }
            else {
                if (!st.empty()) st.pop();
                else if (!ss.empty()) ss.pop();
                else return false;
            }
        }

        while (!st.empty() && !ss.empty()) {
            if (st.top() < ss.top()) {
                st.pop();
                ss.pop();
            }
            else return false;
        }

        return st.empty();
    }
};