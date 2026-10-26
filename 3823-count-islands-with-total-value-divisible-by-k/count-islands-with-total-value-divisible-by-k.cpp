class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    long long dfs(int x, int y, vector<vector<int>>& grid) {
        long long sum = grid[x][y];
        grid[x][y] = 0;

        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= grid.size() ||
                ny < 0 || ny >= grid[0].size() ||
                grid[nx][ny] <= 0)
                continue;

            sum += dfs(nx, ny, grid);
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    if (sum % k == 0) res++;
                }
            }
        }
        return res;
    }
};