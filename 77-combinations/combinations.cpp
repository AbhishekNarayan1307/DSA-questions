class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void solve(int i, int k, int n, vector<int>&op){
        
        if(i > n) return;
        op.push_back(i);
        if(op.size() == k){
            s.insert(op);
            op.pop_back();
            return;
        }
        for(int j = i + 1; j <= n; j++){
            solve(j, k, n, op);
        }
        op.pop_back();
        return;
        

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> op;
        // int i = 1;
        // while(i < n){
        //     solve(i, k, n, op);
        //     i++;
        // }
        for(int i = 1; i <= n; i++){
            solve(i, k ,n, op);
        }
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};