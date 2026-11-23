class Solution {
public:
    int reverse(int x) {
        long long num = abs((long long)x);
        long long rev = 0;
        while(num > 0){
            rev = rev*10 + num%10;
            num /= 10;
        }
        if(x < 0) rev = -rev;
        if(rev < INT_MIN || rev > INT_MAX) return 0;
        else return rev;
    }
};