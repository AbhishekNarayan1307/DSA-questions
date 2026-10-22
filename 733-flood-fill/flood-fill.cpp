class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int col = image[sr][sc];
        image[sr][sc] = color;
        
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        q.push({sr, sc});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto [dx, dy] : dirs){
                int nx = x + dx;
                int ny = y + dy;
                if(nx < 0 || nx >= image.size() || ny < 0 || ny >= image[0].size() || image[nx][ny] != col) continue;
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }
        return image;
    }
};