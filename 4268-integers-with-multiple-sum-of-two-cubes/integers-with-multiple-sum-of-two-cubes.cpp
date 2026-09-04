class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> freq;
        for(int a = 1; 1LL*a*a*a <= n; a++){
            for(int b = a + 1; 1LL*a*a*a + 1LL*b*b*b <= n; b++){
                int sum =  1LL*a*a*a + 1LL*b*b*b;
                freq[sum]++; 
            }
        }
        vector<int> ans;
        for(auto&[sum, count]:freq){
            if(count >= 2) ans.push_back(sum);
        }
        sort(ans.begin(), ans.end());
        return  ans;
    }
};