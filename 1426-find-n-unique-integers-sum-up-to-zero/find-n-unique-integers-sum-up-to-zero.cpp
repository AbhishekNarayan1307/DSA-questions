class Solution {
public:
    vector<int> sumZero(int n) {
        if(n <= 1) return {0};
        vector<int> ans(n);
        if((n%2) == 0){
            int i = 1, l = 1;
            for(int x = n/2; x < n; x++){
                ans[x] = (2*l);
                l++;
            }
            for(int x = n/2 - 1; x >= 0; x--){
                ans[x] = -(2*i);
                i++;
            }
        }
        else{
            ans[n/2] = 0;
            int i = 1, l = 1;
            for(int x = n/2 + 1; x < n; x++){
                ans[x] = (2*l);
                l++;
            }
            for(int x = n/2 - 1; x >= 0; x--){
                ans[x] = -(2*i);
                i++;
            }
        }
        return ans;
    }
};