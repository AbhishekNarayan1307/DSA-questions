class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> img11;
        vector<pair<int,int>> img22;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                    img11.push_back({i, j});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img2[i][j] == 1){
                    img22.push_back({i, j});
                }
            }
        }
        map <pair<int,int>, int> ans;
        for(auto[x, y] : img11){
            for(auto[X, Y] : img22){
                ans[{X-x, Y-y}]++;
            }
        }
        if(ans.empty()) return 0;
        auto it = *max_element(ans.begin(), ans.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        return it.second;
        
    }
};