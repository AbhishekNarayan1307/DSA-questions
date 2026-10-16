class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};

        int m = mat.size(); int n = mat[0].size();
        queue <pair<int, int>> q;
        int mx = m + n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) q.push({i, j});
                else{
                    mat[i][j] = mx;
                }
            }
        }
        vector<pair<int, int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        while(!q.empty()){
            auto[r, c] = q.front(); q.pop();
            for(auto[dr, dc] : dir){
                int x = r + dr;
                int y = c + dc;
                if(x>= 0 && x < m && y >= 0 && y < n && mat[x][y] == mx){
                    q.push({x, y});
                    mat[x][y] = mat[r][c] + 1;
                }
            }
        }
        return mat;



    }
};