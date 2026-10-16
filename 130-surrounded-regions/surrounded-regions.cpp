class Solution {
private:
    vector<pair<int, int>> dirs = {{0,1}, {0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int i, int j){
        vis[i][j] = 1;
        for(auto [x,y] : dirs){
            int nx = i + x;
            int ny = j + y;
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'O' && !vis[nx][ny]){
                dfs(board, vis, nx, ny);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]) dfs(board, vis, 0, j);
        }
        for(int j = 0; j < m; j++){
            if(board[n-1][j] == 'O' && !vis[n-1][j]) dfs(board, vis, n-1, j);
        }
        for(int j = 0; j < n; j++){
            if(board[j][0] == 'O' && !vis[j][0]) dfs(board, vis, j, 0);
        }
        for(int j = 0; j < n; j++){
            if(board[j][m-1] == 'O' && !vis[j][m-1]) dfs(board, vis, j, m-1);
        }
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(board[x][y] == 'O' && !vis[x][y]){
                    board[x][y] = 'X';
                }
            }
        }

    }
};