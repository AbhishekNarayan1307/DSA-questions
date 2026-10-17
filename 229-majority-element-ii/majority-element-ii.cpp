class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        set<int> ans;
        for(int i : nums){
            mp[i]++;
            if(mp[i] > n/3) ans.insert(i);
        }
        vector<int>res;
        for(int s : ans){
            res.push_back(s);
        }        
        return res;
    }
};