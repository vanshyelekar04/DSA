class Solution {
public:
    void helper(int node, vector<vector<int>>& grid, vector<int>& vis){
        vis[node] = 1;
        for(int i=0;i<grid.size();i++){
            if(!vis[i] && grid[node][i]){
                helper(i, grid, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                helper(i, isConnected, vis);
                count++;
            }
        }
        return count;
    }
};