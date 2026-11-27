class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int l = 1;
        int r = x;
        while(l <= r){
            int mid = l + (r-l)/2;
            if((long)mid*mid == (long)x){
                return mid;
            }
            if((long)mid*mid > x){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};