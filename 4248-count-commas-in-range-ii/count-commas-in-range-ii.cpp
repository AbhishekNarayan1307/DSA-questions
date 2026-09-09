class Solution {
public:
    long long countCommas(long long n) {
        long long x = 1000;
        long long res = 0;
        while(x<=n) {
            res += n - x + 1;
            x *= 1000;
        }
        return res;
    }
};