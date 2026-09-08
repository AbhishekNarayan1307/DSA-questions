class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int i, vector<bool> &vis){
        vis[i] = 1;
        for(int it = 0; it < rooms[i].size(); it++){
            if(!vis[rooms[i][it]]){
                dfs(rooms, rooms[i][it], vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
            int i = 0;
            if(!vis[i]){
                dfs(rooms, i, vis);
            }
            for(int x : vis){
                if(x == false) return false;
            }
        return true;
    }
};