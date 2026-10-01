class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> dirs = {{0,-1}, {0, 1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m, false));
        priority_queue <pp, vector<pp>, greater<>> pq;

        for(int i = 0; i < n; i++){
            for(int col : {0, m-1}){
                pq.push({h[i][col], {i, col}});
                vis[i][col] = true;
            }
        }
        for(int j = 0; j < m; j++){
            for(int row : {0, n-1}){
                pq.push({h[row][j], {row, j}});
                vis[row][j] = true;
            }
        }
        int water = 0;
        while(!pq.empty()){
            pp p = pq.top();
            pq.pop();
            int height = p.first;
            int x = p.second.first;
            int y = p.second.second;

            for(auto it : dirs){
                int x_ = x + it[0];
                int y_ = y + it[1];
                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && !vis[x_][y_]){
                    water += max(height - h[x_][y_], 0);
                    pq.push({max(height, h[x_][y_]), {x_, y_}});
                    vis[x_][y_] = true;
                }
            }
        }
        return water;
    }
};