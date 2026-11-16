class Solution {
public:
    string sum(string temp) {
        int res = 0;
        for (char c : temp) {
            res += c - '0';
        }
        return to_string(res);
    }

    string digitSum(string s, int k) {
        string temp = s;

        while (temp.length() > k) {
            string ans = "";

            int l = 0;
            while (l < temp.length()) {
                string temp_ = temp.substr(l, k);
                ans += sum(temp_);
                l += k;
            }

            temp = ans;
        }

        return temp;
    }
};