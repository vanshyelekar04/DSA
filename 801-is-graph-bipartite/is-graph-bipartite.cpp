class Solution {
public:
    bool dfs(int node, int c, vector<int>& vis, vector<vector<int>>& graph){
        vis[node]=c;
        for(int it:graph[node]){
            if(vis[it] == -1){
                if(!dfs(it, 1-c, vis, graph)) return false;
            }else if(vis[it]==vis[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1 && !dfs(i,0,vis, graph)){
                return false;
            }
        }
        return true;
    }
};