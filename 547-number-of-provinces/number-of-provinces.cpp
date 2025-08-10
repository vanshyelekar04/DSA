class Solution {
public:
    void helper(int node, vector<vector<int>>& grid, vector<int>& vis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int i=0;i<grid.size();i++){
                if(i!=k && !vis[i] && grid[k][i]){
                    vis[i] = 1;
                    q.push(i);
                }
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