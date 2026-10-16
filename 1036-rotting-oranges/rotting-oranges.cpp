class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cfo = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) cfo++;
            }
        }

        if(cfo == 0) return 0;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int minutes = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if(grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        cfo--;
                    }
                }
            }

            minutes++;
        }

        return cfo == 0 ? minutes - 1 : -1;
    }
};