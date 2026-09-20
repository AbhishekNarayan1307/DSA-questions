class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            int deg = 'z' - s[i] + 1;
            int pr = deg*(i+1);
            sum += pr;
        }
        return sum;
    }
};