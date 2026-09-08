class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;
        // ls.push_back(node);
        // for(auto it: adj[node]){
        //     if(!vis[it]){
        //         dfs(it, adj, vis, ls);
        //     }
        for(int i=0;i<adj.size();i++){
            if(adj[node][i] == 1 && !vis[i]){
            dfs(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        // vector<int> ls;
        int count = 0;

        for(int i =0; i< n; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                count++;
            }
        }
        return count;


    }
};