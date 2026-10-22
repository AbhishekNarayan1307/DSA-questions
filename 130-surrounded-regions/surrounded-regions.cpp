class Solution {
public:
    vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>> &grid, vector<vector<int>>& vis, int x ,int y){
        vis[x][y] = 1;
        for(auto [dx, dy] : dirs){
            int nx = x+dx;
            int ny = y + dy;
            if(nx <0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || vis[nx][ny] != 0 || grid[nx][ny] != 'O') continue;
            dfs(grid, vis, nx, ny);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(board, vis, i, 0);
        }
        for(int i = 0; i < n; i++){
            if(board[i][m-1] == 'O') dfs(board, vis, i, m-1);
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O') dfs(board, vis, 0, i);
        }
        for(int i = 0; i < m; i++){
        if(board[n-1][i] == 'O') dfs(board, vis, n-1, i);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && vis[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};