class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r){
            if((numbers[l] + numbers[r])==target && l<r) return{l+1, r+1};
            else if((numbers[l] + numbers[r])>target && l<r) r--;
            else{
            if(l<r) l++;
            }
        }
        return {-1,-1};
    }
};